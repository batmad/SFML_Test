#pragma once
#include "json\json.h"

namespace Game {
	class JsonManager {
	public:
		static Json::Value		LoadJson(std::string);
		static void				WriteJson(std::string, Json::Value);
	};
}