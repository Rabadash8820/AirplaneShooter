#include <Game2D.h>
#include <iostream>

int main() {
	// Try to run the game
	try {
		Game2D::Game airplaneShooter("Airplane Shooter");
		airplaneShooter.run();
	}

	// Report any crashes to the console
	catch (std::exception& e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}