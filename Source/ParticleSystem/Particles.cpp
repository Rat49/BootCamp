#include "Particles.h"
#include "EventSystem.h"
#include <SFML/System.hpp>


ParticleSystem::ParticleSystem(unsigned int count, sf::Vector2u canvasSize) :
	_particles(count),
	_vertices(sf::Points, count),
	_emitterPosition(0, 0),
	_canvasSize(canvasSize),
	_emitterVelocity(0, 0)
{
	_zOrder = 2;
	InitializeParticles();
	AddToDrawableManager();

}

void ParticleSystem::InitializeParticles()
{
	for (std::size_t i = 0; i < _particles.size(); ++i)
	{
		Particle& p = _particles[i];
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = 0;
		p._velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		_vertices[i].position = _emitterPosition;
		_particles[i]._currentLifetime = sf::milliseconds((std::rand() % _lifetime));
	}
}

bool SortPair(const std::pair <float, sf::Color> &p1, const std::pair <float, sf::Color> &p2)
{
	return p1.first > p2.first;
}

void ParticleSystem::SortColors()
{
	sort(colors.begin(), colors.end(), SortPair);
	auto t = colors;
}

void ParticleSystem::AddColor(float begin, sf::Color color)
{
	colors.insert(colors.begin(), std::make_pair(begin, color));
	SortColors();
}

void ParticleSystem::SetStandartColors()
{
	colors = {
		{ 1.f, sf::Color::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255)) },
		{ .9f, sf::Color::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(128), static_cast<sf::Uint8>(0), static_cast<sf::Uint8>(255)) },
		{ .7f, sf::Color::Red },
		{ .5f, sf::Color::Color(static_cast<sf::Uint8>(90), static_cast<sf::Uint8>(0), static_cast<sf::Uint8>(57), static_cast<sf::Uint8>(255)) },
		{ .1f, sf::Color::Black }
	};
}

void ParticleSystem::AddCircleForce(sf::Vector2f centre, float radius, float strength) {
	_forces.insert(_forces.begin(), circleForce{ strength, centre, centre, radius });
}

void ParticleSystem::AddCircleForceBehind(float coeff, float radius, float strength) {
	AddCircleForce(_emitterPosition - sf::Vector2f(coeff * _emitterVelocity.x + radius, coeff * _emitterVelocity.y + radius), radius, strength);
	AddCircleForce(_emitterPosition - sf::Vector2f(coeff * _emitterVelocity.x + radius, coeff * _emitterVelocity.y + radius), radius, strength);
	AddCircleForce(_emitterPosition - sf::Vector2f(coeff * _emitterVelocity.x + radius, coeff * _emitterVelocity.y + radius), radius, strength);
	AddCircleForce(_emitterPosition - sf::Vector2f(coeff * _emitterVelocity.x + radius, coeff * _emitterVelocity.y + radius), radius, strength);
}

void ParticleSystem::ChangeColor(const float lifeTime, sf::Vertex& vertex) {
	std::pair<float, sf::Color> tempColor(1.f, sf::Color::Black);
	for (auto &color : colors) {
		if (lifeTime >= color.first)
		{
			vertex.color.r = (lifeTime - color.first)  *(tempColor.second.r - color.second.r) / (tempColor.first - color.first) + color.second.r;
			vertex.color.g = (lifeTime - color.first) *(tempColor.second.g - color.second.g) / (tempColor.first - color.first) + color.second.g;
			vertex.color.b = (lifeTime - color.first) *(tempColor.second.b - color.second.b) / (tempColor.first - color.first) + color.second.b;
			return;
		}
		else {
			tempColor = color;
		}
	}
}

void ParticleSystem::Update(sf::Time elapsed)
{
	int count = 0;
	int invisible = 0;

	for (auto& force : _forces) {
			force.centre.x = force.centreInitial.x + std::rand() % 16 - 8;
			force.centre.y = force.centreInitial.y + std::rand() % 16 - 8;
	}

	for (std::size_t i = 0; i < _particles.size(); ++i)
	{
		Particle& p = _particles[i];
		p._currentLifetime -= elapsed;
		if (p._velocity != sf::Vector2f(0, 0))
			p._velocity += _simpleForce * elapsed.asSeconds();
		_vertices[i].position += p._velocity * elapsed.asSeconds();

		float ratio =  clamp(p._currentLifetime.asSeconds() / p._fullLifetime.asSeconds(), 0.f, 1.f);

		_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

		if (fading && (_vertices[i].color.a - 80) >= 0) {
			_vertices[i].color.a = _vertices[i].color.a - 80;
		}

		if (p._currentLifetime <= sf::Time::Zero && count < _rate)
		{
			ResetParticle(i);
			count++;
		}

		ChangeColor(ratio, _vertices[i]);

		for (auto& force : _forces) {
			
			sf::Vector2f vec = _vertices[i].position - sf::Vector2f(force.centre.x + force.radius, force.centre.y + force.radius);
			float lenght = sqrt(vec.x*vec.x + vec.y*vec.y);
			if (lenght <= force.radius) {
				sf::Vector2f normal = sf::Vector2f(vec.x / sqrt(lenght), vec.y / sqrt(lenght));
				float strength = ((force.radius - sqrt(lenght)) / force.radius) * force.strength;
				p._velocity += normal * strength;

			}
		}

		if ((_vertices[i].position.x > _canvasSize.x
			|| _vertices[i].position.x < 0
			|| _vertices[i].position.y > _canvasSize.y
			|| _vertices[i].position.y < 0
			|| _vertices[i].color.a < 10) && count < _rate)
		{
			ResetParticle(i);
			count++;
		}
		if (_vertices[i].color.a < 10) {
			invisible++;
		}
	}

	for (auto& force : _forces) {

		force.centreInitial += _emitterVelocity * elapsed.asSeconds();
	}
	
	_emitterPosition += _emitterVelocity * elapsed.asSeconds();
	
	if (invisible == _particles.size())
		end = true;
}

void ParticleSystem::ResetParticle(std::size_t index)
{
	float emitterVelocityNorm = sqrt(_emitterVelocity.x*_emitterVelocity.x + _emitterVelocity.y*_emitterVelocity.y);
	if (_emitterVelocity.x >= 0 && _emitterVelocity.y > 0)
	{
		_emitterAngle = acos((_emitterVelocity.x * 0 + _emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0f / 3.14f;
		_emitterAngle = 270 - _emitterAngle;
	}
	if (_emitterVelocity.x >= 0 && _emitterVelocity.y < 0)
	{
		_emitterAngle = acos((_emitterVelocity.x * 1 + _emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0f / 3.14f;
		_emitterAngle = 180 - _emitterAngle;
	}
	if (_emitterVelocity.x < 0 && _emitterVelocity.y >= 0)
	{
		_emitterAngle = acos((-_emitterVelocity.x * 1 + _emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0f / 3.14f;
		_emitterAngle = 0 - _emitterAngle;
	}
	if (_emitterVelocity.x < 0 && _emitterVelocity.y < 0)
	{
		_emitterAngle = acos((_emitterVelocity.x * 0 - _emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0f / 3.14f;
		_emitterAngle = 90 - _emitterAngle;
	}

	float angle;
	if (distribution == Distribution::Normal) {
		std::normal_distribution<float> normal{ _mean, _sigma };
		angle = ((static_cast<int>(normal(gen)) % 360) * 3.14f / 180.f) + (_emitterAngle * 3.14f / 180.f);
	}
	else
	{
		angle = (std::rand() % _range) * 3.14f / 180.f + (_emitterAngle * 3.14f / 180.f) - _range * 3.14f / 360.f;
	}
	float speed = (std::rand() % 5) + _speed;

	_particles[index]._velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	_particles[index]._currentLifetime = sf::milliseconds((std::rand() % 500) + _lifetime);
	_particles[index]._fullLifetime = _particles[index]._currentLifetime;
	_vertices[index].position = _emitterPosition;
}

void ParticleSystem::Draw(sf::RenderWindow & window) 
{
	window.draw(_vertices);

}

void ParticleSystem::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);
}

int ParticleSystem::GetZOrder() const
{
	return _zOrder;
}