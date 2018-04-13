#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

struct Particle : public sf::Drawable
{
	sf::Vertex drawVertex;
	sf::Vector2f vel;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(&drawVertex, 1, sf::Points, states);
	}

};


class ParticleSystem : public sf::Drawable
{
private:
	float _particleSpeed;
	sf::Vector2f _startPos;
	sf::Vector2f _force;
	sf::Vector2u _canvasSize;
	std::vector<std::shared_ptr<Particle>> _particles;
public:
	ParticleSystem(sf::Vector2u canvasSize);
	~ParticleSystem();
	void SetParticleLifeTime(int frames);
	void SetExternalForce(float x, float y) { _force.x = x; _force.y = y; }
	void SetParticleSpeed(float speed) { _particleSpeed = speed; }
	void SetPosition(float x, float y) { _startPos.x = x; _startPos.y = y; }
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	void SetParticleNumber(int particles);
	void Update();
};

