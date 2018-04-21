#pragma once
#include <memory>
#include <algorithm>
#include <random>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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

	ParticleSystem(unsigned int count, sf::Vector2u canvasSize);

	void InitializeParticles();

	void SetEmitterPosition(sf::Vector2f position)		{ _emitterPosition = position;}
	void SetSimpleForce(sf::Vector2f force)				{ _simpleForce = force;}
	void SetEmitterVelocity(sf::Vector2f velocity)		{ _emitterVelocity = velocity; }
	void SetParticlesLifetime(int lifetime)				{ _lifetime = lifetime; }
	void SetRate(int rate)								{ _rate = rate;}
	void SetNormalDistrParams(float mean, float sigma)	{ _mean = mean;_sigma = sigma;}
	void SetUniformDistrRange(int range)				{ _range = range;}
	
	void AddCircleForce(sf::Vector2f centre, float radius, float strenght);
	void AddCircleForceForRocket();
	void Update(sf::Time elapsed);


	Distribution distribution = Distribution::Normal;
	bool fading = false;
	bool end = false;

private:
	struct circleForce {
		float strenght;
		sf::Vector2f centre;
		float radius;
	};
	sf::Vector2f _emitterVelocity;
	sf::Vector2f _emitterPosition;
	sf::Vector2f _simpleForce;
	std::vector<circleForce> _forces;
	sf::Vector2u _canvasSize;
	std::vector<Particle> _particles;
	sf::VertexArray _vertices;
	sf::Time m_lifetime;
	int _lifetime = 3500;
	float _emitterAngle = 180;
	int _rate = 100;
	float _mean = 0;
	float _sigma = 10;
	int _range = 360;
	float _speed = 140.f;
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::vector<std::pair<float, sf::Color>> colors;

	void ResetParticle(std::size_t index);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void ChangeColor(const float lifeTime, sf::Vertex& vertex);
};