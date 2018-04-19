#pragma once
#include <memory>
#include <algorithm>
#include <random>
#include <cassert>
#include <SFML/Graphics.hpp>

struct Particle
{
	sf::Vector2f velocity;
	sf::Time AllLifetime;
	sf::Time lifetime;
};

enum Distribution {
	Normal,
	Uniform
};

template<class T, class Compare>
constexpr const T& clamp(const T& v, const T& lo, const T& hi, Compare comp)
{
	return assert(!comp(hi, lo)),
		comp(v, lo) ? lo : comp(hi, v) ? hi : v;
}

template<class T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi)
{
	return clamp(v, lo, hi, std::less<>());
}

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ParticleSystem(unsigned int count,sf::Vector2u canvasSize) :
		m_particles(count),
		m_vertices(sf::Points, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0), 
		m_canvasSize(canvasSize),
		emitterVelocity(0,0)
	{
		fuel();
	}

	void ParticleSystem::fuel()
	{
		for (std::size_t i = 0; i < m_particles.size(); ++i)
		{
			Particle& p = m_particles[i];
			float angle = (std::rand() % 360) * 3.14f / 180.f;
			float speed = 0;
			p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
			m_vertices[i].position = m_emitter;
			m_particles[i].lifetime = sf::milliseconds((std::rand() % _lifetime));
		}
	}
	void setEmitter(sf::Vector2f position)
	{
		m_emitter = position;
	}

	void AddCircleForce(sf::Vector2f centre, float radius, float strenght) {
		_forces.insert(_forces.begin(), circleForce{ strenght, centre, radius });
	}

	void AddCircleForceForRocket() {
		AddCircleForce(m_emitter - sf::Vector2f(2 * emitterVelocity.x - emitterVelocity.y + 15, 2 * emitterVelocity.y + emitterVelocity.x + 30), 20, -0.5);
		AddCircleForce(m_emitter - sf::Vector2f(4 * emitterVelocity.x + emitterVelocity.y + 10, 4 * emitterVelocity.y - emitterVelocity.x + 10), 20, -0.5);
		AddCircleForce(m_emitter - sf::Vector2f(6 * emitterVelocity.x - emitterVelocity.y + 15, 6 * emitterVelocity.y + emitterVelocity.x +25), 20, -0.5);
	}
	void ChangeColor(const float lifeTime, sf::Vertex& vertex) {
		std::pair<float, sf::Color> tempColor (1.f, sf::Color::Black);
		for (auto &color : colors) {
			if (lifeTime >= color.first)
			{
				vertex.color.r = (lifeTime- color.first)  *(tempColor.second.r - color.second.r) / (tempColor.first - color.first) + color.second.r;
				vertex.color.g = (lifeTime - color.first) *(tempColor.second.g - color.second.g) / (tempColor.first - color.first) + color.second.g;
				vertex.color.b = (lifeTime - color.first) *(tempColor.second.b - color.second.b) / (tempColor.first - color.first) + color.second.b;
				return;
			}
			else {
				tempColor = color;
			}
		}
	}

	void update(sf::Time elapsed)
	{
		int count = 0;
		
		for (std::size_t i = 0; i < m_particles.size(); ++i)
		{
			Particle& p = m_particles[i];
			p.lifetime -= elapsed;
			if (p.velocity!=sf::Vector2f(0,0))
				p.velocity += _simpleForce * elapsed.asSeconds();
			m_vertices[i].position += p.velocity * elapsed.asSeconds();

			float ratio = clamp(p.lifetime.asSeconds() / m_lifetime.asSeconds(), 0.f, 1.f);
			m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
			if (p.lifetime <= sf::Time::Zero && count < _rate)
			{
				resetParticle(i);
				count++;
			}
			auto t = clamp(p.lifetime.asSeconds() /p.AllLifetime.asSeconds(), 0.f, 1.f);
					
			ChangeColor(t, m_vertices[i]);

			for (auto& force : _forces) {
				sf::Vector2f vec = m_vertices[i].position - sf::Vector2f(force.centre.x + force.radius, force.centre.y + force.radius);
				float lenght = sqrt(vec.x*vec.x + vec.y*vec.y);
				if (lenght <= force.radius) {
					sf::Vector2f normal = sf::Vector2f(vec.x / sqrt(lenght), vec.y / sqrt(lenght));
					float strenght = ((force.radius - sqrt(lenght)) / force.radius) * force.strenght;
					p.velocity += normal * strenght;

				}
			}

			if ((m_vertices[i].position.x > m_canvasSize.x
				|| m_vertices[i].position.x < 0
				|| m_vertices[i].position.y > m_canvasSize.y
				|| m_vertices[i].position.y < 0
				|| m_vertices[i].color.a < 10) && count < _rate)
			{
				resetParticle(i);
				count++;
			}
		}

		for (auto& force : _forces) {
			
			force.centre += emitterVelocity * elapsed.asSeconds();
		}
		m_emitter+= emitterVelocity * elapsed.asSeconds();
	}


	void setEmitterPosition(sf::Vector2f position) { m_emitter = position; }
	void setSimpleForce(sf::Vector2f force) { _simpleForce = force; }
	void setEmitterVelocity(sf::Vector2f velocity) { emitterVelocity = velocity; }
	void setRate(int rate) { _rate = rate; }

	void setNormalDistrParams(float mean, float sigma){
		_mean = mean;
		_sigma = sigma;
	}

	void setUniformDistrRange(int range){
		_range = range;
	}

	sf::Vector2f m_emitter;
	sf::Vector2f emitterVelocity;
	Distribution distribution = Distribution::Normal;

private:


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		target.draw(m_vertices, states);

		for each (auto& force in _forces)
		{
			sf::CircleShape shape(force.radius);
			shape.setFillColor(sf::Color(150, 50, 250));
			shape.setPosition(force.centre);
			shape.setFillColor(sf::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(0)));
			target.draw(shape);
		}
	}

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	void initializeParticles(std::size_t index){
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = 0;
		m_particles[index].velocity = sf::Vector2f(0,0);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 500) + 7000);
		m_particles[index].AllLifetime = m_particles[index].lifetime;
		m_vertices[index].position = m_emitter;
	}

	void resetParticle(std::size_t index)
	{
		float emitterVelocityNorm = sqrt(emitterVelocity.x*emitterVelocity.x + emitterVelocity.y*emitterVelocity.y);
		if (emitterVelocity.x >= 0 && emitterVelocity.y > 0)
		{
			_emitterAngle = acos((emitterVelocity.x * 0 + emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0 / 3.14;
			_emitterAngle = 270 - _emitterAngle;
		}
		if (emitterVelocity.x >= 0 && emitterVelocity.y < 0)
		{
			_emitterAngle = acos((emitterVelocity.x * 1 + emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0 / 3.14;
			_emitterAngle = 180 - _emitterAngle;
		}
		if (emitterVelocity.x < 0 && emitterVelocity.y >= 0)
		{
			_emitterAngle = acos((-emitterVelocity.x * 1 + emitterVelocity.y * 0) / emitterVelocityNorm)* 180.0 / 3.14;
			_emitterAngle = 0 - _emitterAngle;
		}
		if (emitterVelocity.x < 0 && emitterVelocity.y < 0)
		{
			_emitterAngle = acos((emitterVelocity.x * 0 - emitterVelocity.y * 1) / emitterVelocityNorm)* 180.0 / 3.14;
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

		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 500) + _lifetime);
		m_particles[index].AllLifetime = m_particles[index].lifetime;

		m_vertices[index].position = m_emitter;
	}

	struct circleForce {
		float strenght;
		sf::Vector2f centre;
		float radius;
	};

	float _emitterAngle = 180;
	int _rate = 10;
	sf::Vector2f _simpleForce;
	std::vector<circleForce> _forces;
	sf::Vector2u m_canvasSize;
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	float _mean=0;
	float _sigma=4;
	int _range = 360;
	int _lifetime = 3500;
	float _speed = 100.f;
	

	std::vector<std::pair<float, sf::Color>> colors = { 
	{ 1.f,sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255)) },
	{ .9f, sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(128),static_cast<sf::Uint8>(0),static_cast<sf::Uint8>(255))},
	{ .7f, sf::Color::Red },
	{ .5f, sf::Color::Color(static_cast<sf::Uint8>(90), static_cast<sf::Uint8>(0), static_cast<sf::Uint8>(57),static_cast<sf::Uint8>(255)) },
	{ .1f,  sf::Color::Black }
	};
};