#pragma once
#include "Drawable.h"
#include "DrawableManager.h"
#include "EventSystem.h"
#include "Pool.h"
#include "WindowResolution.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <algorithm>
#include <cassert>
#include <memory>
#include <random>

static std::random_device rd{};

struct Particle
{
	sf::Vector2f _velocity;
	sf::Time _fullLifetime;
	sf::Time _currentLifetime;
};

enum Distribution {
	Normal,
	Uniform
};

template<class T, class Compare>
constexpr const T& clamp(const T& value, const T& lowerBound, const T& upperBound, Compare comp)
{
	return assert(!comp(upperBound, lowerBound)),
		comp(value, lowerBound) ? lowerBound : comp(upperBound, value) ? upperBound : value;
}

template<class T>
constexpr const T& clamp(const T& value, const T& lowerBound, const T& upperBound)
{
	return clamp(value, lowerBound, upperBound, std::less<>());
}

class ParticleSystem : public Drawable, public sf::Transformable
{
public:

	ParticleSystem(unsigned int count);

	void InitializeParticles();

	void SetEmitterPosition(sf::Vector2f position)		{ _emitterPosition = position;}
	void SetSimpleForce(sf::Vector2f force)				{ _simpleForce = force;}
	void SetEmitterVelocity(sf::Vector2f velocity)		{ _emitterVelocity = velocity; }
	void SetParticlesLifetime(int lifetime)				{ _lifetime = lifetime; }
	void SetRate(int rate)								{ 
		_rate = rate;
	}
	void SetNormalDistrParams(float mean, float sigma)	{ _mean = mean;_sigma = sigma;}
	void SetUniformDistrRange(int range) { _range = range; }
	void SetSpeed(int speed) { _speed = speed; }

	void SortColors();
	void AddColor(float begin, sf::Color color);
	void SetStandartColors();
	void AddCircleForce(sf::Vector2f centre, float radius, float strength);
	void AddCircleForceBehind(float coeff, float radius, float strength);
	void Update(sf::Time elapsed);


	Distribution distribution = Distribution::Normal;
	bool fading = false;
	bool end = false;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow &window) override;
	void AddToDrawableManager() override;



private:
	struct circleForce
    {
		float strength;
		sf::Vector2f centre;
		sf::Vector2f centreInitial;
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
	std::mt19937 gen{ rd() };
	std::vector<std::pair<float, sf::Color>> colors;
	
	
	void ResetParticle(std::size_t index);
	void ChangeColor(const float lifeTime, sf::Vertex& vertex);
};