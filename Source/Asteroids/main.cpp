#include "Asteroids.h"

//const int WINDOW_WIDTH = 1200;
//const int WINDOW_HEIGHT = 800;

std::string GetNameForState(ButtonsState bState) {

	switch (bState)
	{
	case ButtonsState::JustPressed:
		return "JustPressed";
	case ButtonsState::Pressed:
		return "Pressed";
	case ButtonsState::JustReleased:
		return "JustReleased";
	case ButtonsState::Released:
		return "Released";
	default:
		return "Undefined";
		break;
	}
}


int main()
{
	ConfigManager* cm1 = ConfigManager::Create("GameConfig.INI");
	Dispatcher &   dispatcher = Dispatcher::getInstance();
	DrawableManager& drawableManager = DrawableManager::getInstance();

	/*
	ResourceManager Initialization
	*/

	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").GetParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").GetParams()));
	resourceConfig.insert(std::make_pair("TextureResource", cm1->GetCategory("TextureResource").GetParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").GetParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first,
			cm1->GetCategory("ImageSequenceResource." + i.first).GetParams()));
	}

	ResourceManager *rm = new ResourceManager(resourceConfig);

	/*
	InputManager Initialization
	*/

	std::multimap<int, ButtonKey_t> actions;
	LogCategory category = cm1->GetCategory("Input");
	std::multimap<const std::string, const std::string> inputCategory = category.GetParams();
	for (auto i : inputCategory)
	{
		int a = atoi(i.first.c_str());
		int b = atoi(i.second.c_str());
		actions.insert(std::pair<int, int>(a, b));
	}
	InputManager input(actions);
	ButtonsState previousStateMoveUp = ButtonsState::Released;
	ButtonsState previousStateMoveDown = ButtonsState::Released;
	ButtonsState previousStateMoveLeft = ButtonsState::Released;
	ButtonsState previousStateMoveRight = ButtonsState::Released;
	ButtonsState previousStateExit = ButtonsState::Released;
	ButtonsState previousStateChoose = ButtonsState::Released;
	ButtonsState previousStateShoot = ButtonsState::Released;
	ButtonsState previousPowerfullShoot = ButtonsState::Released;

	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateExit;
	ButtonsState stateChoose;
	ButtonsState stateShoot;
	ButtonsState statePowerfullShoot;

	/*
	For Audio
	*/

	//AudioResource* shootingSound = rm->GetResource<AudioResource>("piupiu");
	//AudioResource* explosionSound = rm->GetResource<AudioResource>("booom");

	/*
	For SpaceShip
	*/

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceship");
	ImageSequenceResource* flickeringImgseq = rm->GetResource<ImageSequenceResource>("spaceshipFlickering");
	TextureResource* bulletTexture = rm->GetResource<TextureResource>("bullet");
	TextureResource* rocketTexture = rm->GetResource<TextureResource>("rocket");

	std::multimap<const std::string, const std::string> spaceshipConfig = cm1->GetCategory("SpaceshipConfig").GetParams();
	Spaceship* spaceship = new Spaceship(spaceshipConfig, input, *spaceshipImgseq, *flickeringImgseq);
	spaceship->AddToDrawableManager();
	BulletManager bulletManager(*bulletTexture, *rocketTexture);

	/*
	For Physics
	*/
	CollisionEventBetweenAsteroids collisionAsteroidVsAsteroid;
	CollisionEventBetweenAsteroidAndSpaceship collisionAsteroidVsSpaceship;
	CollisionEventBetweenAsteroidAndRocket collisionAsteroidVsRocket;
	CollisionEventBetweenAsteroidAndBullet collisionAsteroidVsBullet;
	DeleteBulletEvent deleteBulletEvent;
	CreateExplosionEvent createExplosion;

	CollisionEventBetweenAmmunitionAndBullet collisionAmmunitionVsBullet;
	CollisionEventBetweenAmmunitionAndRocket collisionAmmunitionVsRocket;
	CollisionEventBetweenAmmunitionAndSpaceship collisionAmmunitionVsSpaceship;
	CollisionEventBetweenAmmunitionAndAsteroid collisionAmmunitionVsAsteroid;

	constexpr size_t numOfObjects = 10;
	constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
	float           accumulatedFrameTime = 0.f;
	sf::CircleShape circles[numOfObjects];
	RigidBody * RigidBodies = new RigidBody[numOfObjects];
	/*Init rigid bodies and implementation for them*/
	for (int i = 0; i < numOfObjects / 2; i++)
	{
		const int idx = i * 2;
		RigidBodies[idx].SetRadius(10);
		RigidBodies[idx].SetCoordinates({ 500, 200.f + 60 * i });
		RigidBodies[idx].SetSpeed({ 60, 15 });
		RigidBodies[idx].SetMass(0.005f);

		RigidBodies[idx + 1].SetRadius(25);
		RigidBodies[idx + 1].SetCoordinates({ 750, 250.f + 60 * i });
		RigidBodies[idx + 1].SetSpeed({ -100, 40 });
		RigidBodies[idx + 1].SetMass(0.01f);
	}

	for (int i = 0; i < numOfObjects; ++i)
	{
		circles[i].setRadius(RigidBodies[i].GetRadius());
		circles[i].setPosition(RigidBodies[i].GetX(), RigidBodies[i].GetY());
	}

	/*
	Game Loop
	*/

	//sf::RenderWindow rw(sf::VideoMode::getDesktopMode(), "Asteroids");
	sf::RenderWindow rw(sf::VideoMode(1200, 800), "Asteroids");
	WindowResolution::SetResolution(rw);
	sf::Event sysEvent;
	UI ui(rw);

	/*
	For UI
	*/
	sf::Font font;
	sf::Image healthHearth;
	sf::Image bullets;
	sf::Image rockets;
	font.loadFromFile("Resources/font/arial.ttf");
	healthHearth.loadFromFile("Resources/graphics/Health.png");
	bullets.loadFromFile("Resources/graphics/bullets.png");
	rockets.loadFromFile("Resources/graphics/rockets.png");

	ui.CreateLabel("90", font, PercentXY(17, 0), "bulletCount");
	ui.CreatePicture(bullets, PercentXY(20, 1), "bullets");
	ui.CreateLabel("10", font, PercentXY(25, 0), "rocketCount");
	ui.CreatePicture(rockets, PercentXY(28, 1), "rockets");

	ui.CreatePicture(healthHearth, PercentXY(6, 1), "Life0");
	ui.CreatePicture(healthHearth, PercentXY(8, 1), "Life1");
	ui.CreatePicture(healthHearth, PercentXY(10, 1), "Life2");
	ui.CreateLabel("100", font, PercentXY(0, 0), "HP");
	ui.CreateLabel("0", font, PercentXY(95, 0), "score");


	/*
	For Space
	*/

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroidTexture");

	sf::Texture asteroidTexture = asteroid->Get();
	sf::Sprite spriteAsteroid(asteroidTexture);

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	const int totalCountStar = (WindowResolution::_W / 50) * (WindowResolution::_H / 50) + 10;
	Space space(totalCountAsteroids, totalCountStar, rw.getSize());


	int _nStars = (WindowResolution::_W / 50) * (WindowResolution::_H / 50) - 300;
	int _nAsteroids = (WindowResolution::_W / 200) + (WindowResolution::_H / 200) + 5;

	space.AddSomeStars(_nStars);
	space.AddSomeAsteroids(_nAsteroids, spriteAsteroid);
	space.AddAmmunition(rm);
	/*
	DebugCommandManager manager
	*/
	DebugCommandManager manager;

	manager.addConsoleCommand({ "setInvincibility", [&spaceship](const std::vector<std::string>& args)
	{
		spaceship->SetDamage(0);
	} });

	manager.addConsoleCommand({ "unsetInvincibility", [&spaceship, &spaceshipConfig](const std::vector<std::string>& args)
	{
		spaceship->SetDamage(atoi(spaceshipConfig.find("Damage")->second.c_str()));
	} });

	manager.addConsoleCommand({ "setCollidersVisible", [&spaceship, &space, &bulletManager](const std::vector<std::string>& args)
	{
		spaceship->SetColliderVisible(true);
		space.SetColliderVisible(true);
	} });

	manager.addConsoleCommand({ "setCollidersInvisible", [&spaceship, &space, &bulletManager](const std::vector<std::string>& args)
	{
		spaceship->SetColliderVisible(false);
		space.SetColliderVisible(false);
	} });

	spaceship->SetColliderVisible(false);
	space.SetColliderVisible(false);
	/*
	For Debug Console
	*/
	DebugConsole debugConsole(rw);

	/*
	For Log
	*/
	Logger& log = Logger::GetInstance();
	sf::Clock clock;
	sf::Time fixedTime;
	sf::Time deltaTime;
	const sf::Time fixedUpdateTime = sf::milliseconds(3);

	while (rw.isOpen())
	{
		deltaTime = clock.restart();
		fixedTime += deltaTime;

		//std::cout << "deltaTime = " << deltaTime.asMicroseconds() << "\n";

		input.Update();
		if (input.GetMode() == InputMode::Paused || input.GetMode() == InputMode::PausedRaw)
		{
			fixedTime = sf::Time::Zero;
		}

		if (rw.pollEvent(sysEvent))
		{

			if (input.GetMode() == InputMode::Raw || input.GetMode() == InputMode::PausedRaw)
			{
				input.HandleRawEvent(sysEvent);
				debugConsole.setActiveConsoleStatus(true);
			}
			else
			{
				debugConsole.setActiveConsoleStatus(false);
			}
		}

		if (fixedTime > fixedUpdateTime)
		{

			//Input update
			{
				if (input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && previousStateMoveUp != stateMoveUp)
				{
					std::cout << "MoveUp state - " << GetNameForState(stateMoveUp) << std::endl;
					previousStateMoveUp = stateMoveUp;
				}
				if (input.GetState(static_cast<int>(GameActions::MoveDown), stateMoveDown) && previousStateMoveDown != stateMoveDown)
				{
					std::cout << "MoveDown state - " << GetNameForState(stateMoveDown) << std::endl;
					previousStateMoveDown = stateMoveDown;
				}
				if (input.GetState(static_cast<int>(GameActions::MoveLeft), stateMoveLeft) && previousStateMoveLeft != stateMoveLeft)
				{
					std::cout << "MoveLeft state - " << GetNameForState(stateMoveLeft) << std::endl;
					previousStateMoveLeft = stateMoveLeft;
				}
				if (input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && previousStateMoveRight != stateMoveRight)
				{
					std::cout << "MoveRight state - " << GetNameForState(stateMoveRight) << std::endl;
					previousStateMoveRight = stateMoveRight;
				}
				if (input.GetState(static_cast<int>(GameActions::Exit), stateExit) && stateExit == ButtonsState::JustPressed)
				{
					rw.close();
					//previousStateExit = stateExit;
				}
				if (input.GetState(static_cast<int>(GameActions::Choose), stateChoose) && previousStateChoose != stateChoose)
				{
					std::cout << "Choose state - " << GetNameForState(stateChoose) << std::endl;
					previousStateChoose = stateChoose;
				}
				if (input.GetState(static_cast<int>(GameActions::SuperShoot), statePowerfullShoot) && previousPowerfullShoot != statePowerfullShoot)
				{
					std::cout << "SuperShoot state - " << GetNameForState(statePowerfullShoot) << std::endl;
					previousPowerfullShoot = statePowerfullShoot;
				}
				if (input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && previousStateShoot != stateShoot)
				{
					std::cout << "Shoot state - " << GetNameForState(stateShoot) << std::endl;
					previousStateShoot = stateShoot;
				}
			}
			//Audio update
			//Logic update

			size_t n = space.asteroids.size();
			size_t m = space.asteroids.size();
			size_t bulletsSize = bulletManager.bullets.size();
			size_t rocketSize = bulletManager.rockets.size();

			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = i + 1; j < m; ++j)
				{
					
					if (Collided(*space.asteroids[i], *space.asteroids[j]))
					{
						collisionAsteroidVsAsteroid._asteroid1 = space.asteroids[i];
						collisionAsteroidVsAsteroid._asteroid2 = space.asteroids[j];
						ResolveCollision(*space.asteroids[i], *space.asteroids[j]);
						dispatcher.Send(collisionAsteroidVsAsteroid, collisionEventID, space.asteroids[i]->_tokens[collisionEventID]);
						dispatcher.Send(collisionAsteroidVsAsteroid, collisionEventID, space.asteroids[j]->_tokens[collisionEventID]);
					}
				}

				if (Collided(*space.asteroids[i], *spaceship))
				{
					collisionAsteroidVsSpaceship._asteroid = space.asteroids[i];
					collisionAsteroidVsSpaceship._spaceship = spaceship;
					ResolveCollision(*space.asteroids[i], *spaceship);
					dispatcher.Send(collisionAsteroidVsSpaceship, collisionEventBetweenAsteroidAndSpaceshipID, space.asteroids[i]->_tokens[collisionEventBetweenAsteroidAndSpaceshipID]);
					dispatcher.Send(collisionAsteroidVsSpaceship, collisionEventBetweenAsteroidAndSpaceshipID, spaceship->_tokens[collisionEventBetweenAsteroidAndSpaceshipID]);
				}

			for (size_t j = 0; j < rocketSize; ++j)
			{
				if (Collided(*space.asteroids[i], *bulletManager.rockets[j]))
				{
					collisionAsteroidVsRocket._asteroid = space.asteroids[i];
					collisionAsteroidVsRocket._rocket = bulletManager.rockets[j];
					createExplosion.position = space.asteroids[i]->GetCoordinates();
					ResolveCollision(*space.asteroids[i], *bulletManager.rockets[j]);
					dispatcher.Send(collisionAsteroidVsRocket, collisionEventBetweenAsteroidAndRocketID, space.asteroids[i]->_tokens[collisionEventBetweenAsteroidAndRocketID]);
					dispatcher.Send(createExplosion, createExplosionEvent, space._createExplosion);
					dispatcher.Send(collisionAsteroidVsRocket, collisionEventBetweenAsteroidAndRocketID, bulletManager.rockets[j]->_tokens[collisionEventBetweenAsteroidAndRocketID]);
					for (size_t k = 0; k < n; ++k) {
						if (Collided(*space.asteroids[k], *bulletManager.rockets[j]))
						{
							collisionAsteroidVsRocket._asteroid = space.asteroids[k];
							collisionAsteroidVsRocket._rocket = bulletManager.rockets[j];
							ResolveCollision(*space.asteroids[k], *bulletManager.rockets[j]);
							createExplosion.position = space.asteroids[k]->GetCoordinates();
							dispatcher.Send(createExplosion, createExplosionEvent, space._createExplosion);
							dispatcher.Send(collisionAsteroidVsRocket, collisionEventBetweenAsteroidAndRocketID, space.asteroids[k]->_tokens[collisionEventBetweenAsteroidAndRocketID]);
						
						}
					}
					bulletManager.DeleteRocket(bulletManager.rockets[j]);
				}
			}

				for (auto bullet : bulletManager.bullets)
				{
					if (Collided(*space.asteroids[i], *bullet))
					{
						collisionAsteroidVsBullet._asteroid = space.asteroids[i];
						collisionAsteroidVsBullet._bullet = bullet;
						deleteBulletEvent._deletedBullet = bullet;
						ResolveCollision(*space.asteroids[i], *bullet);
						createExplosion.position = space.asteroids[i]->GetCoordinates();
						dispatcher.Send(createExplosion, createExplosionEvent, space._createExplosion);
						dispatcher.Send(collisionAsteroidVsBullet, collisionEventBetweenAsteroidAndBulletID, space.asteroids[i]->_tokens[collisionEventBetweenAsteroidAndBulletID]);
						dispatcher.Send(deleteBulletEvent, deleteBulletEventID, bulletManager.deleteBullet);
					}
				}
			}
			{
				for (auto asteroid : space.asteroids)
				{
					if (Collided(*asteroid, *space.ammunition))
					{
						collisionAmmunitionVsAsteroid.asteroid = asteroid;
						collisionAmmunitionVsAsteroid.ammunition = space.ammunition;
						ResolveCollision(*asteroid, *space.ammunition);
						dispatcher.Send(collisionAmmunitionVsAsteroid, collisionEventID, asteroid->_tokens[collisionEventID]);
						dispatcher.Send(collisionAmmunitionVsAsteroid, collisionEventBetweenAmmunitionAndAsteroidId, space.ammunition->_tokens[collisionEventBetweenAmmunitionAndAsteroidId]);
					}
				}
				if (Collided(*spaceship, *space.ammunition))
				{
					collisionAmmunitionVsSpaceship.spaceship = spaceship;
					collisionAmmunitionVsSpaceship.ammunition = space.ammunition;
					ResolveCollision(*spaceship, *space.ammunition);
					dispatcher.Send(collisionAmmunitionVsSpaceship, collisionEventBetweenAmmunitionAndSpaceshipId, spaceship->_tokens[collisionEventBetweenAmmunitionAndSpaceshipId]);
					space.ammunition->capacity = 0;
					dispatcher.Send(collisionAmmunitionVsSpaceship, collisionEventBetweenAmmunitionAndSpaceshipId, space.ammunition->_tokens[collisionEventBetweenAmmunitionAndSpaceshipId]);

				}
				for (auto rocket : bulletManager.rockets)
				{
					if (Collided(*rocket, *space.ammunition))
					{
						collisionAmmunitionVsRocket.rocket = rocket;
						collisionAmmunitionVsRocket.ammunition = space.ammunition;
						ResolveCollision(*rocket, *space.ammunition);
						createExplosion.position = space.ammunition->GetCoordinates();
						dispatcher.Send(createExplosion, createExplosionEvent, space._createExplosion);
						dispatcher.Send(collisionAmmunitionVsRocket, collisionEventBetweenAmmunitionAndRocketId, rocket->_tokens[collisionEventBetweenAmmunitionAndRocketId]);
						dispatcher.Send(collisionAmmunitionVsRocket, collisionEventBetweenAmmunitionAndRocketId, space.ammunition->_tokens[collisionEventBetweenAmmunitionAndRocketId]);
						bulletManager.DeleteRocket(rocket);
					}
					
				}
				for (auto bullet : bulletManager.bullets)
				{
					if (Collided(*bullet, *space.ammunition))
					{
						collisionAmmunitionVsBullet.bullet = bullet;
						collisionAmmunitionVsBullet.ammunition = space.ammunition;
						ResolveCollision(*bullet, *space.ammunition);
						createExplosion.position = space.ammunition->GetCoordinates();
						deleteBulletEvent._deletedBullet = bullet;
						dispatcher.Send(createExplosion, createExplosionEvent, space._createExplosion);
						dispatcher.Send(deleteBulletEvent, deleteBulletEventID, bulletManager.deleteBullet); 
						dispatcher.Send(collisionAmmunitionVsBullet, collisionEventBetweenAmmunitionAndBulletId, space.ammunition->_tokens[collisionEventBetweenAmmunitionAndBulletId]);
					}
				}
			}

			/*space.Update(deltaTime.asMilliseconds() / 1e3);
			spaceship->Update(deltaTime);
			bulletManager.Update(deltaTime);*/

			//space.Update(fixedTime.asMilliseconds() / 1e3);
			space.Update(fixedTime.asSeconds());
			spaceship->Update(fixedTime);
			bulletManager.Update(fixedTime);

			fixedTime = sf::Time::Zero;
		}
		rw.clear();
		//Rendering update
		//for (int i = 0; i < numOfObjects; ++i)
		//{
		//	rw.draw(circles[i]);
		//}
		//
		//DebugConsole 
		if (debugConsole.getActiveConsoleStatus())
		{
			debugConsole.Draw(rw);
		}
		drawableManager.DrawScene(rw);
		ui.Render();
	}

	
	delete cm1;
	return 0;
}