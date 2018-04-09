#include "ConfigManager.h"


const char* LogCategory::getValue(const char* configValue) {
	
	//if ( params.empty() )
	//....

	//if ( params[configValue] exist )

	return params[configValue];

}

/*
----------------------------------------------------------------------------
*/

void ConfigManager::readInputFile(std::string file_name) {

	in_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		in_file.open(file_name);

		createCategories();

		in_file.close();
	}
	catch (const std::ifstream::failure&) {
		std::cerr << "Cannon open/read file!" << std::endl;
	}

}

void ConfigManager::createCategories() {

	std::string line;
	
	while (in_file.is_open()) {

		if (!in_file.eof()){
			std::getline(in_file, line);
			if (line[0] == '[') {

				std::ostringstream os;

				for (int i = 1; i < line.size() - 1, line[i] != ']'; ++i) {
					os << line[i];
				}

				std::string categoryName = os.str();

				//std::cout << categoryName << std::endl;
				//system("PAUSE");

				if (!in_file.eof()) {
					std::getline(in_file, line);
					while (line[0] != '[') {

					}
				}

				//LogCategory category(createParameters(categoryName));
				//logCategories.insert(std::pair<const char*, LogCategory>(categoryName.c_str(), category));
			}
		}
	}
}

std::pair<const char*, const char*>& ConfigManager::createParameter(std::string line) {

	std::pair<const char*, const char*> param;

	/*
	while () {

		const char* key;
		const char* value;

		params.insert(std::pair<const char*, const char*>(key, value));
	}
	*/
	return param;
}

LogCategory& ConfigManager::getCategory(const char* categoryName) {
	
	return logCategories[categoryName];
}