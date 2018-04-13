#include "Particles.h"
#include <random>



ParticleSystem::ParticleSystem(sf::Vector2u canvasSize)
{
	_particleSpeed = 12;
	_canvasSize = canvasSize;
}


ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::SetParticleLifeTime(int frames) {

}
void ParticleSystem::draw(
		sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& item : _particles)
		target.draw(&item.get()->drawVertex, 1, sf::Points);
	return;
}

void ParticleSystem::SetParticleNumber(int particles) {
	for (int i = 0; i < particles; i++)
	{
		Particle* particle;
		particle = new Particle();
		particle->drawVertex.position.x = _startPos.x;
		particle->drawVertex.position.y = _startPos.y;

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_real_distribution<> randomSide(-1.0f, 1.0f);
			particle->vel.x = randomSide(gen);
			particle->vel.y = randomSide(gen);

		if (particle->vel.x == 0.0f && particle->vel.y == 0.0f)
		{
			delete particle;
			continue;
		}

		std::uniform_real_distribution<> randomColor(0, 255);
		particle->drawVertex.color.r = randomColor(gen);
		particle->drawVertex.color.g = randomColor(gen);
		particle->drawVertex.color.b = randomColor(gen);
		particle->drawVertex.color.a = 255;

		_particles.push_back(std::shared_ptr<Particle>(particle));
	}

	return;

}
void ParticleSystem::Update() {

	for (auto it = _particles.begin(); it != _particles.end(); it++)
	{
		(*it)->vel.x += _force.x;
		(*it)->vel.y += _force.y;

		(*it)->drawVertex.position.x += (*it)->vel.x * _particleSpeed;
		(*it)->drawVertex.position.y += (*it)->vel.y * _particleSpeed;


		if ((*it)->drawVertex.position.x > _canvasSize.x
			|| (*it)->drawVertex.position.x < 0
			|| (*it)->drawVertex.position.y > _canvasSize.y
			|| (*it)->drawVertex.position.y < 0
			|| (*it)->drawVertex.color.a < 10)
		{
			it = _particles.erase(it);
			if (it == _particles.end()) return;
		}
	}

	return;
}