#pragma once
#include "Particles.h"
class RocketParticle : public PoolElement
{
public:
	ParticleSystem particles;

	RocketParticle(unsigned int quantity) :
		particles(quantity)
	{
		particles.SetNormalDistrParams(0, 12);
		particles.SetStandartColors();
		particles.SetParticlesLifetime(400);
		particles.SetRate(30);
	}

	RocketParticle() : RocketParticle(500) {}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void AddForces() {
		particles.AddCircleForceBehind(0.2f, 20, -1);
		particles.AddCircleForceBehind(0.4f, 20, 0.3f);
		particles.AddCircleForceBehind(0.6f, 20, -1);
		particles.AddCircleForceBehind(0.8f, 20, 0.5f);
	}

	void SetVelocity(sf::Vector2f velocity) {
		particles.SetEmitterVelocity(velocity);
	}

	void Reset(){
		particles.end = false;
		particles.fading = false;
		particles.SetRate(30);
		particles.InitializeParticles();
	}

	void Play() {
		particles.AddToDrawableManager();
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

class ExplosionParticle : public PoolElement {
public:
	ParticleSystem particles;
	sf::Time reccomendedLifeTime = sf::seconds(0.2f);

	ExplosionParticle(unsigned int quantity) :
		particles(quantity) {
		particles.SetRate(30);
		particles.SetNormalDistrParams(0, 160);
		particles.SetParticlesLifetime(100);
		particles.SetStandartColors();
		particles.SetSpeed(400.f);
		particles.AddToDrawableManager();
		reccomendedLifeTime = sf::seconds(0.13f);
	}

	ExplosionParticle() : ExplosionParticle(500) {}

	void SetPosition(sf::Vector2f position) {
		particles.SetEmitterPosition(position);
	}

	void Stop() {
		particles.SetRate(0);
	}

	void Reset() {
		particles.fading = false;
		particles.end = false;
		particles.SetRate(30);
		particles.InitializeParticles();
		reccomendedLifeTime = sf::seconds(0.2f);
	}

	void Play() {
		particles.AddToDrawableManager();
	/*	particles.fading = false;
		particles.SetRate(150);
		particles.InitializeParticles();
		reccomendedLifeTime = sf::seconds(0.2f);
		particles.Update(sf::seconds(0.2f));*/
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

	SpaceshipParticle(unsigned int quantity) :
		particles(500) {
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