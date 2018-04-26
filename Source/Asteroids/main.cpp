#include "Asteroids.h"

//enum class GameActions {
//	MoveUp,
//	MoveDown,
//	MoveLeft,
//	MoveRight,
//	Exit,
//	Choose,
//	Shoot,
//	PowerfullShoot,
//	Console
//};
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

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

	Spaceship* spaceship = new Spaceship(sf::Vector2f(450.0f, 450.0f), sf::Vector2f(0.0f, 15.0f), input, *spaceshipImgseq, *flickeringImgseq);
	//spaceship->SetMass(10000);
	spaceship->AddToDrawableManager();
	BulletManager bulletManager(*bulletTexture, *rocketTexture);
	
	/*
	For Physics
	*/
	CollisionEventBetweenAsteroids collisionAsteroidVsAsteroid;
	CollisionEventBetweenAsteroidAndSpaceship collisionAsteroidVsSpaceship;
	CollisionEventBetweenAsteroidAndRocket collisionAsteroidVsRocket;
	CollisionEventBetweenAsteroidAndBullet collisionAsteroidVsBullet;

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
		RigidBodies[idx + 1].SetSpeed({ -100, 40});
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

	/*
	For Space
	*/

	TextureResource* asteroid = rm->GetResource<TextureResource>("asteroidTexture");
	sf::Texture asteroidTexture = asteroid->Get();
	sf::Sprite spriteAsteroid(asteroidTexture);

	std::srand(std::time(nullptr));

	const int totalCountAsteroids = 100;
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Space space(totalCountAsteroids, totalCountStar, rw.getSize());


	int _nStars = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50)-300;
	int _nAsteroids = (WINDOW_WIDTH / 200) + (WINDOW_HEIGHT / 200) + 5;

	space.AddSomeStars(_nStars);
	space.AddSomeAsteroids(_nAsteroids, spriteAsteroid);
	/*
	For Debug Console
	*/
	DebugConsole debugConsole(rw);

	/*
	For Log
	*/
	Logger& log = Logger::GetInstance();
	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	while (rw.isOpen())
	{

		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		if (rw.pollEvent(sysEvent))
		{
			
			if (input.GetMode() == InputMode::Raw)
			{
				input.HandleRawEvent(sysEvent);
				debugConsole.setActiveConsoleStatus(true);
			}
			else
			{
				debugConsole.setActiveConsoleStatus(false);
			}
			input.Update();
		}

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
				std::cout << "Choose state - " << GetNameForState(statePowerfullShoot) << std::endl;
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

		size_t n = space._asteroids.size() - 1;
		size_t m = space._asteroids.size();
		size_t bulletsSize = bulletManager.bullets.size();
		size_t rocketSize = bulletManager.rockets.size();

		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = i + 1; j < m; ++j)
			{
				if (Collided(*space._asteroids[i], *space._asteroids[j]))
				{
					collisionAsteroidVsAsteroid._asteroid1 = space._asteroids[i];
					collisionAsteroidVsAsteroid._asteroid2 = space._asteroids[j];
					ResolveCollision(*space._asteroids[i], *space._asteroids[j]);
					dispatcher.Send(collisionAsteroidVsAsteroid, collisionEventID, space._asteroids[i]->_tokens[collisionEventID]);
					dispatcher.Send(collisionAsteroidVsAsteroid, collisionEventID, space._asteroids[j]->_tokens[collisionEventID]);
				}
			}

			if (Collided(*space._asteroids[i],*spaceship))
			{
				collisionAsteroidVsSpaceship._asteroid = space._asteroids[i];
				collisionAsteroidVsSpaceship._spaceship = spaceship;
				ResolveCollision(*space._asteroids[i], *spaceship);
				dispatcher.Send(collisionAsteroidVsSpaceship, collisionEventBetweenAsteroidAndSpaceshipID, space._asteroids[i]->_tokens[collisionEventBetweenAsteroidAndSpaceshipID]);
				dispatcher.Send(collisionAsteroidVsSpaceship, collisionEventBetweenAsteroidAndSpaceshipID, spaceship->_tokens[collisionEventBetweenAsteroidAndSpaceshipID]);
			}

			/*for (size_t j = 0; j < rocketSize; ++j)
			{
				if (Collided(*space._asteroids[i], *bulletManager.rockets[j]))
				{
					collisionAsteroidVsRocket._asteroid = space._asteroids[i];
					collisionAsteroidVsRocket._rocket = bulletManager.rockets[j];
					ResolveCollision(*space._asteroids[i], *bulletManager.rockets[j]);
					dispatcher.Send(collisionAsteroidVsRocket, collisionEventBetweenAsteroidAndRocketID, space._asteroids[i]->_token);
					dispatcher.Send(collisionAsteroidVsRocket, collisionEventBetweenAsteroidAndRocketID, bulletManager.rockets[j]->_token);
				}
			}
*/
			for (size_t j = 0; j < bulletsSize; ++j)
			{
				if (Collided(*space._asteroids[i], *bulletManager.bullets[j]))
				{
					collisionAsteroidVsBullet._asteroid = space._asteroids[i];
					collisionAsteroidVsBullet._bullet = bulletManager.bullets[j];
					ResolveCollision(*space._asteroids[i], *bulletManager.bullets[j]);
					dispatcher.Send(collisionAsteroidVsBullet, collisionEventBetweenAsteroidAndBulletID, space._asteroids[i]->_tokens[collisionEventBetweenAsteroidAndBulletID]);
					dispatcher.Send(collisionAsteroidVsBullet, collisionEventBetweenAsteroidAndBulletID, bulletManager.bullets[j]->_tokens[collisionEventBetweenAsteroidAndBulletID]);
				}
			}

		}
		space.Update(deltaTime.asMilliseconds() / 1e3);

		spaceship->Update(deltaTime);
		bulletManager.Update(deltaTime);

		//Physics update
		{
			/*for (int i = 0; i < numOfObjects; ++i)
				circles[i].setFillColor(sf::Color::White);
			while (accumulatedFrameTime >= physicsStepTargetFrameTime)
			{
				accumulatedFrameTime -= physicsStepTargetFrameTime;
				for (int i = 0; i < numOfObjects - 1; ++i)
				{
					for (int j = i + 1; j < numOfObjects; ++j)
					{
						if (Collided(RigidBodies[i], RigidBodies[j]))
						{
							circles[i].setFillColor(sf::Color::Red);
							circles[j].setFillColor(sf::Color::Red);
							collisionAsteroidVsAsteroid._asteroid1 = &RigidBodies[i];
							collisionAsteroidVsAsteroid._asteroid2 = &RigidBodies[j];
							dispatcher.Send(collisionAsteroidVsAsteroid, collisionEventID);
							ResolveCollision(RigidBodies[i], RigidBodies[j]);
						}
					}
				}

				for (int i = 0; i < numOfObjects; ++i)
				{
					RigidBodies[i].Update(physicsStepTargetFrameTime / 1e3);
					circles[i].setPosition(RigidBodies[i].GetX(), RigidBodies[i].GetY());
				}
			}*/
		}
		//...

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
		//Display
		rw.display();
	}

	delete[] RigidBodies;
	delete cm1;
	return 0;
}