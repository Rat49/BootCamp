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


	void ChangeColor(const float lifeTime, sf::Vertex& vertex) {
		std::pair<float, sf::Color> tempColor (1.f, sf::Color::Black);
		for (auto &color : colors) {
			if (lifeTime >= color.first)
			{
				vertex.color.r = (lifeTime- color.first) *(tempColor.second.r - color.second.r)/(tempColor.first - color.first) + color.second.r;
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
		for (std::size_t i = 0; i < m_particles.size(); ++i)
		{
			Particle& p = m_particles[i];
			p.lifetime -= elapsed;
			if (p.velocity!=sf::Vector2f(0,0))
				p.velocity += _force * elapsed.asSeconds();
			m_vertices[i].position += p.velocity * elapsed.asSeconds();

			float ratio = clamp(p.lifetime.asSeconds() / m_lifetime.asSeconds(), 0.f, 1.f);
			m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
			if (p.lifetime <= sf::Time::Zero)
				resetParticle(i);
			auto t = clamp(p.lifetime.asSeconds() /p.AllLifetime.asSeconds(), 0.f, 1.f);
					
			sf::Vertex c = m_vertices[i];
			ChangeColor(t, m_vertices[i]);
			//if (m_vertices[i].position.x < 10 && m_vertices[i].position.y<10)
				//std::cout << m_vertices[i].position.x << " "<< m_vertices[i].position.y << std::endl;
			if (m_vertices[i].position.x > m_canvasSize.x
				|| m_vertices[i].position.x < 0
				|| m_vertices[i].position.y > m_canvasSize.y
				|| m_vertices[i].position.y < 0
				|| m_vertices[i].color.a < 10)
			{
				resetParticle(i);
			}

		}
		m_emitter.x++;
		m_emitter.y++;
	}
	void setForce(sf::Vector2f force) { _force = force; }
private:

	sf::Vector2f _force;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = NULL;

		target.draw(m_vertices, states);
	}

private:

	void initializeParticles(std::size_t index){
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = 0;
		m_particles[index].velocity = sf::Vector2f(0,0);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 3000));
		m_particles[index].AllLifetime = m_particles[index].lifetime;
		m_vertices[index].position = m_emitter;
	}

	void resetParticle(std::size_t index)
	{
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = (std::rand() % 5) + 20.f;
		m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
		m_particles[index].lifetime = sf::milliseconds((std::rand() % 500) + 1000);
		m_particles[index].AllLifetime = m_particles[index].lifetime;

		m_vertices[index].position = m_emitter;
	}
	float _particleSpeed = 50;
	sf::Vector2u m_canvasSize;
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	std::vector<std::pair<float, sf::Color>> colors = { 
	{ 1.f,sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(255)) },
	{ .7f, sf::Color::Color(static_cast<sf::Uint8>(255),static_cast<sf::Uint8>(128),static_cast<sf::Uint8>(0),static_cast<sf::Uint8>(255))},
	{ .6f, sf::Color::Red },
	{ .2f, sf::Color::Color(static_cast<sf::Uint8>(100), static_cast<sf::Uint8>(100), static_cast<sf::Uint8>(100),static_cast<sf::Uint8>(255)) },
	//{ .2f, sf::Color::Color(static_cast<sf::Uint8>(133), static_cast<sf::Uint8>(133), static_cast<sf::Uint8>(133),static_cast<sf::Uint8>(255)) },
	{ .1f,  sf::Color::Black }
	};
};