#include "Input.h"
#include "Physics.h"
#include "Spaceship.h"
#include "DrawableManager.h"
#include "Pool.h"
#include <iostream>

//Spaceship::Spaceship(sf::Vector2f position, sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
//	AnimationPlayer* spaceshipAnimation, AnimationPlayer* ordinaryShotAnimation, AnimationPlayer* powerfulShotAnimation)
//	: RigidBody(position, speed, spaceshipAnimation->GetWidth() / 2.0f, 1.0f)
//	, _spaceshipDirection(spaceshipDirection)
//	, _input(input)
//	, _spaceshipAnimation(spaceshipAnimation)
//	, _ordinaryShotAnimation(ordinaryShotAnimation)
//	, _powerfulShotAnimation(powerfulShotAnimation)
//	, _spaceshipSprite(spaceshipAnimation->GetSprite())
//	, _isRecharged(true)
//	, _rotationAngle(10.0f)
//	, _rebound(35.001f)
//	, _powerfulRebound(25.1f)
//	, _currentAngle(0.0f)
//	, _inputTime(sf::milliseconds(100))
//	, _inputAccumulatedTime(sf::milliseconds(0))
//	, _bulletDeltaAngle(5.0f)
//	, _deltaSpeed(sf::Vector2f(5.0f, 5.0f))
//	, _maxSquareSpeed(5000.0f)
//{
//	//_ordinaryBulletStorage = Pool<OrdinaryBullet>(100);
//	//_rocketStorage = Pool<RocketBullet>(10);
//	Add();
//	_spaceshipSprite->setPosition(position);
//	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
//	_spaceshipAnimation->Start();
//
//}

Spaceship::Spaceship(sf::Vector2f position, sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager & input, 
	ImageSequenceResource &spaceshipAnimationImseq, ImageSequenceResource &ordinaryShotAnimationImseq, ImageSequenceResource &powerfulShotAnimationImseq)
	: RigidBody(position, speed, spaceshipAnimationImseq.GetWidth() / 2.0f, 1.0f)
	, _spaceshipDirection(spaceshipDirection)
	, _input(input)
	//, _spaceshipAnimation(spaceshipAnimation)
	//, _ordinaryShotAnimation(ordinaryShotAnimation)
	//, _powerfulShotAnimation(powerfulShotAnimation)
	//, _spaceshipSprite(spaceshipAnimation->GetSprite())
	, _isRecharged(true)
	, _rotationAngle(10.0f)
	, _rebound(35.001f)
	, _powerfulRebound(25.1f)
	, _currentAngle(0.0f)
	, _inputTime(sf::milliseconds(100))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _bulletDeltaAngle(5.0f)
	, _deltaSpeed(sf::Vector2f(5.0f, 5.0f))
	, _maxSquareSpeed(5000.0f)
	, _ordinaryShotAnimationImseq(ordinaryShotAnimationImseq)
	, _powerfulShotAnimationImseq(powerfulShotAnimationImseq)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
{
	_spaceshipSprite = new sf::Sprite();
	_spaceshipAnimation = new AnimationPlayer(*_spaceshipSprite, spaceshipAnimationImseq, true);
	Add();
	_spaceshipSprite->setPosition(position);
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();
	
}

void Spaceship::Accelerate()
{
	sf::Vector2f newSpeed = GetSpeed() + _deltaSpeed;
	if (GetSquareLength(newSpeed) < _maxSquareSpeed)
	{
		SetSpeed(newSpeed);
	}
}

void Spaceship::Decelerate()
{
	sf::Vector2f newSpeed = GetSpeed() - _deltaSpeed;
	if (GetSquareLength(newSpeed) < _maxSquareSpeed)
	{
		SetSpeed(newSpeed);
	}
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot < _rechargeTime)
		return;

	//Rocket rocketLeft = Rocket(speedValue * _spaceshipDirection, sprite, animationPlayer);
	
	//ChangeSpeed(_rebound);

	//_speed = sf::Vector2f(_speed.x - _spaceshipDirection.x * _powerfulRebound, _speed.y - _spaceshipDirection.y * _powerfulRebound);
	//==========================only for test=======================================
	std::cout << "PowerfulShoot" << std::endl;
	std::cout << GetSpeed().x << " " << GetSpeed().y << std::endl;
	//==============================================================================
	// SetSpeed()

	_timeAfterPowerfulShot = sf::seconds(0.0f); 
}


void Spaceship::OrdinaryShoot()
{
	std::cout << "Spaceship position" << GetX() << " " << GetY() << std::endl;

	//sf::Sprite* spriteLeft = new sf::Sprite();
	//sf::Sprite* spriteRight = new sf::Sprite();
	//AnimationPlayer* _ordinaryShotAnimationLeft = new AnimationPlayer(*spriteLeft, _ordinaryShotAnimationImseq, true);
	//AnimationPlayer* _ordinaryShotAnimationRight = new AnimationPlayer(*spriteRight, _ordinaryShotAnimationImseq, true);


	sf::Transform rotation;
	rotation.rotate(_bulletDeltaAngle, _spaceshipSprite->getOrigin());
	OrdinaryBullet * bulletLeft = new OrdinaryBullet(_spaceshipSprite->getPosition(), NormalizedDirection(), _ordinaryShotAnimationImseq);
	
	//OrdinaryBullet* bullet = _ordinaryBulletStorage.Get();
	//bullet->Init(_spaceshipSprite->getPosition(), NormalizedDirection());

	_bullets.push_back(bulletLeft);

	//rotation.rotate(-_bulletDeltaAngle, _spaceshipSprite->getPosition());
	//sf::Vector2f bulletRightDirection = rotation.transformPoint(_spaceshipDirection);
	//spriteRight->setPosition(GetCoordinates());
	//OrdinaryBullet * bulletRight = new OrdinaryBullet(GetCoordinates(), NormalizedDirection(bulletRightDirection), _ordinaryShotAnimationRight);
	//_bullets.push_back(bulletRight);

	//ChangeSpeed(_rebound);
	//_speed = sf::Vector2f(_speed.x - _spaceshipDirection.x * _rebound, _speed.y - _spaceshipDirection.y * _rebound);

	//==========================only for test=======================================
	std::cout << "OrdinaryShoot" << std::endl;
	std::cout << GetSpeed().x << " " << GetSpeed().y << std::endl;
	//==============================================================================
}

void Spaceship::RotateSpaceship(float angle)
{
	sf::Transform rotation;
	rotation.rotate(angle, _spaceshipSprite->getOrigin());
	_spaceshipDirection = rotation.transformPoint(_spaceshipDirection);
	//_spaceshipDirection = NormalizedDirection();
	//==========================only for test=========================================
	std::cout << _spaceshipDirection.x << " " << _spaceshipDirection.y << std::endl;
	//================================================================================

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);	
}

void Spaceship::ChangeSpeed(float deltaSpeed)
{
	sf::Vector2f direction = NormalizedDirection();
	SetSpeed(GetSpeed() - deltaSpeed * direction);
}

float Spaceship::GetSquareLength(sf::Vector2f speed) const
{
	return speed.x * speed.x + speed.y * speed.y;
}

sf::Vector2f Spaceship::NormalizedDirection()
{
	return _spaceshipDirection / std::sqrt(GetSquareLength(_spaceshipDirection));
}

sf::Vector2f Spaceship::NormalizedDirection(sf::Vector2f v)
{
	float length = std::sqrt(GetSquareLength(v));
	return sf::Vector2f(v.x / length, v.y / length);
}

void Spaceship::Update(sf::Time deltaTime)
{

	//============temporary===============
	enum class GameActions {
		MoveUp,
		MoveDown,
		MoveLeft,
		MoveRight,
		Exit,
		Choose,
		Shoot,
		SuperShoot
	};
	//====================================

	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateShoot;
	ButtonsState stateSuperShoot;

	_input.Update();
	if (_input.GetState(static_cast<int>(GameActions::MoveLeft), stateMoveLeft) && (stateMoveLeft == ButtonsState::JustPressed || stateMoveLeft == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else 
		{
			RotateSpaceship(-_rotationAngle);
			_inputAccumulatedTime = sf::milliseconds(0);
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && (stateMoveRight == ButtonsState::JustPressed || stateMoveRight == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			RotateSpaceship(_rotationAngle);
			_inputAccumulatedTime = sf::milliseconds(0);
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && (stateMoveUp == ButtonsState::JustPressed || stateMoveUp == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			Accelerate();
			_inputAccumulatedTime = sf::milliseconds(0);
			//==========================only for test=======================================
			std::cout << GetSpeed().x << " " << GetSpeed().y << std::endl;
			//==============================================================================
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveDown), stateMoveDown) && (stateMoveDown == ButtonsState::JustPressed || stateMoveDown == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			Decelerate();
			_inputAccumulatedTime = sf::milliseconds(0);
			//==========================only for test=======================================
			std::cout << GetSpeed().x << " " << GetSpeed().y << std::endl;
			//==============================================================================
		}
	}

	
	if (_input.GetState(static_cast<int>(GameActions::SuperShoot), stateSuperShoot) && stateSuperShoot == ButtonsState::JustPressed)
	{
		PowerfulShoot();
	}
	//========================Shoot is not exists in InputManager============================
	if (_input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && stateShoot == ButtonsState::JustPressed)
	{
		OrdinaryShoot();
	}
	//=======================================================================================



	_timeAfterPowerfulShot += deltaTime;
	RigidBody::Update(deltaTime.asSeconds());
	_spaceshipSprite->setPosition(RigidBody::GetCoordinates());
	_spaceshipAnimation->Update(deltaTime);


	for (auto bullet : _bullets)
	{
		bullet->Update(deltaTime);
	}

	//=======================================================================================
	//std::cout << _speed.x << " " << _speed.y << std::endl;
	//=======================================================================================

	
}


void Spaceship::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();
}

int Spaceship::GetZOrder() const
{
	return _zOrder;
}

void Spaceship::Draw(sf::RenderWindow & window)
{
	window.draw(*(_spaceshipAnimation->GetSprite()));
}

Spaceship::~Spaceship()
{

}