#include "AirplaneShooter.h"
#include <iostream>

int main() {
	// Run the game
	try {
		Shooter::AirplaneShooter game;
		game.run();
	}

	// Report any crashes to the console
	catch (std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}