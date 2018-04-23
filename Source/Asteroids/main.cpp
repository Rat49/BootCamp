#include "Asteroids.h"

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot,
	Console
};


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

	/*
	ResourceManager Initialization
	*/

	std::map<std::string, std::multimap<const std::string, const std::string>> resourceConfig;
	resourceConfig.insert(std::make_pair("AudioResource", cm1->GetCategory("AudioResource").getParams()));
	resourceConfig.insert(std::make_pair("PictureResource", cm1->GetCategory("PictureResource").getParams()));
	std::multimap<const std::string, const std::string> imageSequenceCategory = cm1->GetCategory("ImageSequenceResource").getParams();
	resourceConfig.insert(std::make_pair("ImageSequenceResource", imageSequenceCategory));
	std::vector<std::multimap<const std::string, const std::string>> imageSequenceSettings(imageSequenceCategory.size());

	for (auto i : imageSequenceCategory)
	{
		resourceConfig.insert(std::make_pair("ImageSequenceResource." + i.first, 
			cm1->GetCategory("ImageSequenceResource." + i.first).getParams()));
	}

	ResourceManager *rm = new ResourceManager(resourceConfig);

	/*
	InputManager Initialization
	*/

	std::multimap<int, ButtonKey_t> actions;
	LogCategory category = cm1->GetCategory("Input");
	std::multimap<const std::string, const std::string> inputCategory = category.getParams();
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

	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateExit;
	ButtonsState stateChoose;
	ButtonsState stateShoot;

	/*
	For Physics
	*/
	CollisionEvent collisionEvent;
	dispatcher.Connect(collisionEventID, ResolveCollision);
	constexpr size_t numOfObjects = 10;
	constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
	float           accumulatedFrameTime = 0.f;
	sf::CircleShape circles[numOfObjects];
	RigidBody * RigidBodies = new RigidBody[numOfObjects];
	/*Init rigid bodies and implementation for them*/
	for (int i = 0; i < numOfObjects / 2; i++)
	{
		const int idx = i * 2;
		RigidBodies[idx]._radius =10;
		RigidBodies[idx]._coords = { 500, 200.f + 60 * i };
		RigidBodies[idx]._speed = { 60, 15 };
		RigidBodies[idx]._mass = 0.005f;

		RigidBodies[idx + 1]._radius = 25;
		RigidBodies[idx + 1]._coords = { 750, 250.f + 60 * i };
		RigidBodies[idx + 1]._speed = { -100, 40};
		RigidBodies[idx + 1]._mass = 0.01f;
	}

	for (int i = 0; i < numOfObjects; ++i)
	{
		circles[i].setRadius(RigidBodies[i]._radius);
		circles[i].setPosition(RigidBodies[i]._coords.x, RigidBodies[i]._coords.y);
	}
	

	/*
	Game Loop
	*/

	//sf::RenderWindow rw(sf::VideoMode::getDesktopMode(), "Asteroids");
	sf::RenderWindow rw(sf::VideoMode(1200, 800), "Asteroids");
	sf::Event sysEvent;
	sf::Clock clock;
	sf::Time  deltaTime;

	/*
	For Debug Console
	*/
	DebugConsole debugConsole(rw);

	/*
	For Log
	*/
	Logger& log = Logger::GetInstance();


	while (rw.isOpen())
	{
		const float delta = clock.restart().asMicroseconds() / 1e3;
		accumulatedFrameTime += delta;

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
			if (input.GetState(static_cast<int>(GameActions::Exit), stateExit) && previousStateExit != stateExit)
			{
				rw.close();
				//previousStateExit = stateExit;
			}
			if (input.GetState(static_cast<int>(GameActions::Choose), stateChoose) && previousStateChoose != stateChoose)
			{
				std::cout << "Choose state - " << GetNameForState(stateChoose) << std::endl;
				previousStateChoose = stateChoose;
			}
			if (input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && previousStateShoot != stateShoot)
			{
				std::cout << "Shoot state - " << GetNameForState(stateShoot) << std::endl;
				previousStateShoot = stateShoot;
			}
		}
		//Audio update
		//Logic update
		//Physics update
		{
			for (int i = 0; i < numOfObjects; ++i)
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
							collisionEvent.setObjs(&RigidBodies[i], &RigidBodies[j]);
							dispatcher.Send(collisionEvent, collisionEventID);
							//ResolveCollision(RigidBodies[i], RigidBodies[j]);
						}
					}
				}

				for (int i = 0; i < numOfObjects; ++i)
				{
					RigidBodies[i].Update(physicsStepTargetFrameTime / 1e3);
					circles[i].setPosition(RigidBodies[i]._coords.x, RigidBodies[i]._coords.y);
				}
			}
		}
		//...

		rw.clear();
		//Rendering update
		for (int i = 0; i < numOfObjects; ++i)
		{
			rw.draw(circles[i]);
		}
		
		//DebugConsole 
		if (debugConsole.getActiveConsoleStatus())
		{
			debugConsole.Draw(rw);
		}

		//Display
		rw.display();
	}
	delete[] RigidBodies;
	delete cm1;
	return 0;
}