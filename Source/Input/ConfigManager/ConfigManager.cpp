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
	std::string value;
	std::regex pattern("\[[A-Za-z]*\]");
	
	while (in_file.is_open()) {

		std::getline(in_file, line);
		if (std::regex_search(line, value, pattern)) {
			
			std::string categoryName = value.substr(1, value.size()-2);

			//LogCategory category(createParameters(categoryName));
			//logCategories.insert(std::pair<const char*, LogCategory>(categoryName.c_str(), category));
		}
	}
}

std::map<const char*, const char*>& ConfigManager::createParameters(std::string categoryName) {

	std::map<const char*, const char*> params;

	/*
	while () {

		const char* key;
		const char* value;

		params.insert(std::pair<const char*, const char*>(key, value));
	}
	*/
	return params;
}

LogCategory& ConfigManager::getCategory(const char* categoryName) {
	
	return logCategories[categoryName];
}