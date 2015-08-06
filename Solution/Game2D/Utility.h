#pragma once

#include "GAME2D_API.h"

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Window\Keyboard.hpp>

#include <string>
#include <sstream>

// Define a general macro to get the current working directory
#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

namespace Game2D {

	class GAME2D_API Utility {
	private:
		Utility();

		// STATIC INTERFACE
	public:
		static std::string currentWorkingDirectory();
		static void centerOrigin(sf::Sprite&);
		static void centerOrigin(sf::Text&);
		static std::string toString(sf::Keyboard::Key);
		template <typename T>
		static std::string toString(const T& value) {
			std::stringstream stream;
			stream << value;
			return stream.str();
		}
	};

}
