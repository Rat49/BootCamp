#include "ConfigManager.h"
#include "Logger.h"

const char* InvalidCategory = "Invalid_category";

bool LogCategory::IfElementExists(const std::string& keyValue) const
{
	return (_params.find(keyValue) != _params.end());
}

std::vector<Param> LogCategory::GetValues(const std::string& keyValue) const
{
	auto range = _params.equal_range(keyValue);
	return { range.first, range.second };
}

void LogCategory::AddNewParam(const Param& param)
{
	_params.insert(param);
}

std::multimap<const std::string, const std::string> LogCategory::GetParams() const
{
	return _params;
}

size_t LogCategory::Size()
{
	return _params.size();
}

ConfigManager* ConfigManager::Create(const std::string& fileName)
{
	ConfigManager* cm = new ConfigManager();
	cm->ReadInputFile(fileName);
	return cm;
}

void ConfigManager::ReadInputFile(const std::string& fileName)
{
	inFile.open(fileName);

	if (inFile.is_open())
	{
		CreateCategories();
		inFile.close();
	}
	else
	{
		Logger::GetInstance().Error("Can't open file");
	}
}

void ConfigManager::CreateCategories()
{
	std::string line;
	std::string currentCategory = "";

	while (!inFile.eof())
	{
		std::getline(inFile, line);

		if (line[0] == '[')
		{
			std::ostringstream oss;

			for (int i = 1; i < line.size() - 1; ++i)
			{
				if (line[i] != ']')
				{
					oss << line[i];
				}
			}
			currentCategory = oss.str();
			logCategories[currentCategory] = LogCategory();
		}
		else
		{
			CreateParameter(currentCategory, line);
		}
	}

	logCategories[InvalidCategory] = LogCategory();
}

void ConfigManager::CreateParameter(const std::string& categoryName, const std::string& line)
{
	if (line.empty())
	{
		return;
	}

	std::vector<std::string> keyAndArgs = parser.Split(line, "=");
	std::string key = keyAndArgs[0];
	parser.Trim(key);

	std::vector<std::string> args = parser.Split(keyAndArgs[1], ",");
	if (!key.empty() && !args.empty())
	{
		for (auto arg : args)
		{
			parser.Trim(arg);
			logCategories[categoryName].AddNewParam({ key, arg });
		}
	}
}

bool ConfigManager::IfCategoryExists(const std::string& keyValue) const
{
	return (logCategories.find(keyValue) != logCategories.end());
}

LogCategory& ConfigManager::GetCategory(const std::string& categoryName) {

	if (IfCategoryExists(categoryName))
	{
		return logCategories[categoryName];
	}

	Logger::GetInstance().Error("Category value not found");
	return logCategories[InvalidCategory];
}
