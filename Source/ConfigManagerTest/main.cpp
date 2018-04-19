#include "ConfigManager.h"
#include <iostream>

namespace ConfigManagerTest {


	void Test() {

		std::cout << "Test input files" << std::endl;
		std::cout << "Wrong input file:" << std::endl;
		ConfigManager* cm1 = ConfigManager::Create("testCcccconfig.INI");
		std::cout << "Correct input file:" << std::endl;
		ConfigManager* cm2 = ConfigManager::Create("testConfig.INI");

		std::cout << "Test config values" << std::endl;
		std::cout << "Correct values:" << std::endl;
		std::cout << "returned value: " << cm2->GetCategory("Input").GetValue("SHOOT") << std::endl;
		std::cout << "Wrong category value:" << std::endl;
		std::cout << "returned value: " << cm2->GetCategory("Innnput").GetValue("SHOOT") << std::endl;
		std::cout << "Wrong config value:" << std::endl;
		std::cout << "returned value: " << cm2->GetCategory("Input").GetValue("SHOOOOT") << std::endl;
		std::cout << "Wrong category and config values:" << std::endl;
		std::cout << "returned value: " << cm2->GetCategory("Innnput").GetValue("SHOOOOT") << std::endl;

		
		if (cm1 != NULL) {
			delete cm1;
		}

		if (cm2 != NULL) {
			delete cm2;
		}

	}

}


int main() {

	ConfigManagerTest::Test();

	return 0;
}