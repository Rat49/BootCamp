#include"ConfigManager.h"


int main() {

	ConfigManager* configManager = ConfigManager::create("config.INI");
	configManager->getCategory("Input").getValue("SHOOT");

	return 0;
}