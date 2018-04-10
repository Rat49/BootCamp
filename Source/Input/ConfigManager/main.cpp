#include"ConfigManager.h"


int main() {


	ConfigManager cm;

	cm.readInputFile("config.INI");

	cm.getCategory("Input").getValue("SHOOT");


	return 0;
}