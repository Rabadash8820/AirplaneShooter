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

		template <typename T>
		static std::string toString(const T& value) {
			std::stringstream stream;
			stream << value;
			return stream.str();
		}
		static std::string toString(sf::Keyboard::Key);

		static float toRadians(float);
		static float toDegrees(float);

		static sf::Vector2f unitVector(sf::Vector2f);
		static float distance(sf::Vector2f, sf::Vector2f);

	};

}
