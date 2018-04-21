#include "Particles.h"
#include <SFML/System.hpp>


ParticleSystem::ParticleSystem(unsigned int count, sf::Vector2u canvasSize) :
	_particles(count),
	_vertices(sf::Points, count),
	m_lifetime(sf::seconds(3)),
	_emitterPosition(0, 0),
	_canvasSize(canvasSize),
	_emitterVelocity(0, 0)
{
	InitializeParticles();
}

void ParticleSystem::InitializeParticles()
{
	colors = {
		{ 1.f, sf::Color::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255)) },
		{ .9f, sf::Color::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(128), static_cast<sf::Uint8>(0), static_cast<sf::Uint8>(255)) },
		{ .7f, sf::Color::Red },
		{ .5f, sf::Color::Color(static_cast<sf::Uint8>(90), static_cast<sf::Uint8>(0), static_cast<sf::Uint8>(57), static_cast<sf::Uint8>(255)) },
		{ .1f, sf::Color::Black }
	};
	for (std::size_t i = 0; i < _particles.size(); ++i)
	{
		Particle& p = _particles[i];
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = 0;
		p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		_vertices[i].position = _emitterPosition;
		_particles[i].lifetime = sf::milliseconds((std::rand() % _lifetime));
	}
}

void ParticleSystem::AddCircleForce(sf::Vector2f centre, float radius, float strenght) {
	_forces.insert(_forces.begin(), circleForce{ strenght, centre, radius });
}

void ParticleSystem::AddCircleForceForRocket() {
	float radius = 40;
	AddCircleForce(_emitterPosition - sf::Vector2f(3 * _emitterVelocity.x + radius, 3 * _emitterVelocity.y + radius), 40, -0.3);
	AddCircleForce(_emitterPosition - sf::Vector2f(6 * _emitterVelocity.x + radius, 6 * _emitterVelocity.y + radius), 40, 0.3);
	AddCircleForce(_emitterPosition - sf::Vector2f(9 * _emitterVelocity.x + radius, 9 * _emitterVelocity.y + radius), 40, -0.3);
	AddCircleForce(_emitterPosition - sf::Vector2f(12 * _emitterVelocity.x + radius, 12 * _emitterVelocity.y + radius), 40, 0.3);
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
	for (std::size_t i = 0; i < _particles.size(); ++i)
	{
		Particle& p = _particles[i];
		p.lifetime -= elapsed;
		if (p.velocity != sf::Vector2f(0, 0))
			p.velocity += _simpleForce * elapsed.asSeconds();
		_vertices[i].position += p.velocity * elapsed.asSeconds();

		float ratio =  clamp(p.lifetime.asSeconds() / p.AllLifetime.asSeconds(), 0.f, 1.f);

		_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

		if (fading && (_vertices[i].color.a - 80) >= 0) {
			_vertices[i].color.a = _vertices[i].color.a - 80;
		}

		if (p.lifetime <= sf::Time::Zero && count < _rate)
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
				float strenght = ((force.radius - sqrt(lenght)) / force.radius) * force.strenght;
				p.velocity += normal * strenght;

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

		force.centre += _emitterVelocity * elapsed.asSeconds();
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
		_emitterAngle = acos((_emitterVelocity.x * 0 + _emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0 / 3.14;
		_emitterAngle = 270 - _emitterAngle;
	}
	if (_emitterVelocity.x >= 0 && _emitterVelocity.y < 0)
	{
		_emitterAngle = acos((_emitterVelocity.x * 1 + _emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0 / 3.14;
		_emitterAngle = 180 - _emitterAngle;
	}
	if (_emitterVelocity.x < 0 && _emitterVelocity.y >= 0)
	{
		_emitterAngle = acos((-_emitterVelocity.x * 1 + _emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0 / 3.14;
		_emitterAngle = 0 - _emitterAngle;
	}
	if (_emitterVelocity.x < 0 && _emitterVelocity.y < 0)
	{
		_emitterAngle = acos((_emitterVelocity.x * 0 - _emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0 / 3.14;
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

	_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	_particles[index].lifetime = sf::milliseconds((std::rand() % 500) + _lifetime);
	_particles[index].AllLifetime = _particles[index].lifetime;
	_vertices[index].position = _emitterPosition;
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(_vertices, states);

}
