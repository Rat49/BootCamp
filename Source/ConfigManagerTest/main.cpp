#include "ConfigManager.h"
#include <iostream>

namespace ConfigManagerTest {


	void Test() {

		std::cout << "Test input files" << std::endl;
		std::cout << "Wrong input file:" << std::endl;
		ConfigManager* cm1 = ConfigManager::Create("testCcccconfig.INI");
		std::cout << "Correct input file:" << std::endl;
		ConfigManager* cm2 = ConfigManager::Create("testConfig.INI");
		LogCategory input = cm2->GetCategory("Input");
		LogCategory audio = cm2->GetCategory("Audio");

		for (auto value : cm2->GetCategory("Input").GetValues("SHOOT"))
		{
			std::cout << "returned value: " << value.second << std::endl;
		}

		
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