#include <iostream>
#include <fstream>
#include "JsonManager.h"

using namespace Game;

Json::Value JsonManager::LoadJson(std::string path) {
	Json::Value root;
	Json::Reader reader;
	std::ifstream input(path + ".json");
	bool parseSuccess = reader.parse(input, root);
	if (!parseSuccess)
		std::cout << "Fail to load: " << reader.getFormattedErrorMessages();
	input.close();
	return root;
}

void JsonManager::WriteJson(std::string path, Json::Value root) {
	Json::StyledStreamWriter writer;
	std::ofstream mOutput(path + ".json");
	writer.write(mOutput, root);
}