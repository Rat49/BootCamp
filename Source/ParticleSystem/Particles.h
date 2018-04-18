#pragma once
#include <memory>
#include <algorithm>
#include <random>
#include <cassert>
#include <SFML/Graphics.hpp>

class Particle
{
public:
	sf::Vector2f velocity;
	sf::Time AllLifetime;
	sf::Time lifetime;
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



typedef std::uniform_real_distribution<> UniRealDist;
typedef std::uniform_int_distribution<> UniIntDist;

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ParticleSystem(unsigned int count,sf::Vector2u canvasSize) :
		m_particles(count),
		m_vertices(sf::Points, count),
		m_lifetime(sf::seconds(3)),
		m_emitter(0, 0), 
		m_canvasSize(canvasSize)
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
			m_particles[i].lifetime = sf::milliseconds((std::rand() % 4000));
		}
	}
	void setEmitter(sf::Vector2f position)
	{
		m_emitter = position;
	}

	void AddCircleForce(sf::Vector2f centre, float radius, float strenght) {
		_forces.insert(_forces.begin(), circleForce{ strenght, centre, radius });
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
		//std::cout << "update" << std::endl;
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
			if (p.lifetime <= sf::Time::Zero && count <= _rate)
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
				|| m_vertices[i].color.a < 10) && count <= _rate)
			{
				resetParticle(i);
				count++;
			}
		}
		for (auto& force : _forces) {
			
			force.centre += emitterVelocity * elapsed.asSeconds();
		}
		m_emitter+= emitterVelocity * elapsed.asSeconds();
		//_emitterAngle; 
	}
	void setEmitterPosition(sf::Vector2f position) { m_emitter = position; }
	void setSimpleForce(sf::Vector2f force) { _simpleForce = force; }
	void setEmitterVelocity(sf::Vector2f velocity) { 
		emitterVelocity = velocity; 
		/*AddCircleForce(m_emitter-sf::Vector2f(2* velocity.x+3, 2 * velocity.y), 20, -3);
		AddCircleForce(m_emitter - sf::Vector2f(3 * velocity.x - 3, 3 * velocity.y), 20, -3);
		AddCircleForce(m_emitter - sf::Vector2f(4 * velocity.x + 3, 4 * velocity.y), 20, -3);*/
	}
	void setRate(int rate) { _rate = rate; }
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
			shape.setFillColor(sf::Color(static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(255), static_cast<sf::Uint8>(50)));
			target.draw(shape);
		}
	}
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::normal_distribution<> d{ 0, 12 };

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
		//std::cout << "reset" << std::endl;
		_emitterAngle = acos((emitterVelocity.x * 0 + emitterVelocity.y * 1) / (sqrt(emitterVelocity.x*emitterVelocity.x + emitterVelocity.y*emitterVelocity.y)))* 180.0 / 3.14;
		if (emitterVelocity.x > 0 && emitterVelocity.y > 0)
			_emitterAngle = _emitterAngle + 180;
		if (emitterVelocity.x > 0 && emitterVelocity.y < 0)
			_emitterAngle = _emitterAngle + 0;
		if (emitterVelocity.x < 0 && emitterVelocity.y > 0)
			_emitterAngle = _emitterAngle + 270;
		if (emitterVelocity.x < 0 && emitterVelocity.y < 0)
			_emitterAngle = _emitterAngle + 270;
		float angle = ((static_cast<int>(d(gen)) % 360) * 3.14f / 180.f)+(_emitterAngle * 3.14f / 180.f);// (std::rand() % 6)
		float speed = (std::rand() % 5) + 100.f;
		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 500) +3000);
		m_particles[index].AllLifetime = m_particles[index].lifetime;

		m_vertices[index].position = m_emitter;
	}

	struct circleForce {
		float strenght;
		sf::Vector2f centre;
		float radius;
	};
	float _emitterAngle = 180;
	int _rate = 0;
	sf::Vector2f _simpleForce;
	std::vector<circleForce> _forces;
	sf::Vector2u m_canvasSize;
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	sf::Vector2f emitterVelocity;
	std::vector<std::pair<float, sf::Color>> colors = { 
	{ 1.f,sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255)) },
	{ .7f, sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(128),static_cast<sf::Uint8>(0),static_cast<sf::Uint8>(255))},
	{ .6f, sf::Color::Red },
	{ .2f, sf::Color::Color(static_cast<sf::Uint8>(100), static_cast<sf::Uint8>(100), static_cast<sf::Uint8>(100),static_cast<sf::Uint8>(255)) },
	{ .1f,  sf::Color::Black }
	};
};