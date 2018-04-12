#include "Pool.h"
#include "Logger.h"
#include <iostream>

namespace PoolTest
{
	class Sample : public PoolElement
	{
	public:
		void Reset() override
		{
			std::cout << "reset called\n";
		}
	};

	void Test()
	{
		std::cout << "Test fundamental type\n";
		Pool<float> pool1(10);
		std::cout << "Count before get: " << pool1.Count() << "\n";
		auto p1 = pool1.Get();
		std::cout << "Count after get: " << pool1.Count() << "\n";
		pool1.Put(p1);
		std::cout << "Count after put: " << pool1.Count() << "\n";

		std::cout << "Test complex type\n";
		Pool<Sample> pool2(10);
		std::cout << "Count before get: " << pool2.Count() << "\n";
		auto p2 = pool2.Get();
		std::cout << "Count after get: " << pool2.Count() << "\n";
		pool2.Put(p2);
		std::cout << "Count after put: " << pool2.Count() << "\n";
	}
}

namespace LoggerTest
{
	
	void Test()
	{
		Logger& log = Logger::getInstance();
		log.setFrame(400);
		auto cmdTarget = log.AddCmdTarget();
		auto fileTarget = log.AddFileTarget("../Events/Event.log");
		fileTarget->includeChannel("Event");
		cmdTarget->SetSeverity(LogLevel::WARNING);
		fileTarget->SetSeverity(LogLevel::INFO);
		cmdTarget->includeChannel("All");
		log("Audio").Debug("%s %s!", "Hello", "world");
		log("Event").Info("%s %s!", "Hello", "world");
		cmdTarget->excludeChannel("All");
		cmdTarget->includeChannel("Audio");
		log("Audio").Error("%s %s!", "Hello", "world");
		log("Event").Warning("%s %s!", "Hello", "world");
	}
}


int main()
{
	PoolTest::Test();

	LoggerTest::Test();

	system("pause");
	return 0;
}