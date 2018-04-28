#pragma once
#include "Particles.h"
#include "Pool.h"
class RocketParticle : public PoolElement
{
public:
	ParticleSystem particles;

	RocketParticle(unsigned int quantity, sf::Vector2u window) :
		particles(2000, window)
	{
		particles.SetNormalDistrParams(0, 12);
		particles.SetStandartColors();
		particles.SetParticlesLifetime(400);
		particles.SetRate(10);
	}

	RocketParticle() : RocketParticle(1000, sf::Vector2u(500, 500)) {}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
		particles.AddCircleForceBehind(0.5f, 20, -2);
		particles.AddCircleForceBehind(1.5f, 20, 0.3f);
		particles.AddCircleForceBehind(2.5f, 20, -2);
		particles.AddCircleForceBehind(3.5f, 20, 0.5f);
	}

	void Reset(){

		particles.end = false;
		particles.InitializeParticles();
		//particles.Update(sf::seconds(0.002f));
	}
	void Play() {
		particles.SetRate(10);
		particles.fading = false;
		//particles.Update(sf::seconds(0.002f));
		particles.end = false;
	}

	void Stop() {
		particles.SetRate(0);
	}


	void Update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};

class ExplosionParticle {
public:
	ParticleSystem particles;
	sf::Time reccomendedLifeTime = sf::seconds(0.2f);

	ExplosionParticle(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		//в конструкторе рэйт = 0
		particles.SetRate(150);
		particles.SetNormalDistrParams(0, 160);
		particles.SetParticlesLifetime(500);
		particles.SetStandartColors();
		particles.SetSpeed(200.f);

	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void Stop() {
		particles.SetRate(0);
	}

	void Reset() {
		particles.SetRate(0);
	}

	void Play() {
		particles.fading = false;
		particles.SetRate(150);
		particles.InitializeParticles();
		reccomendedLifeTime = sf::seconds(0.2f);
		particles.Update(sf::seconds(0.2f));
	}

	void Update(sf::Time deltaTime) {
		reccomendedLifeTime -= deltaTime;
		if (reccomendedLifeTime <= sf::Time::Zero)
		{
			particles.SetRate(0);
			particles.fading = true;
		}
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};

class SpaceshipParticle {
public:
	ParticleSystem particles;

	SpaceshipParticle(unsigned int quantity, sf::Vector2u window) :
		particles(1000, window) {
		particles.SetParticlesLifetime(50);
	}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
		particles.AddCircleForceBehind(0.5f, 20, -1);
		particles.AddCircleForceBehind(1.5f, 20, 0.7f);
	}

	void Stop() {
		particles.fading = true;
		particles.SetRate(0);
	}
	void Play() {
		particles.fading = false;
		particles.InitializeParticles();
		particles.SetRate(10);
	}

	void Update(sf::Time deltaTime) {
		particles.Update(deltaTime);
	}

	bool IsEnd() {
		return particles.end;
	}
};