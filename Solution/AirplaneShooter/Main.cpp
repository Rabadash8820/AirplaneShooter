#include "Game.h"
#include <iostream>

using namespace std;

int main() {
	// Run the game
	try {
		Shooter::Game game;
		game.run();
	}

	// Report any crashes to the console
	catch (exception& e) {
		cout << "EXCEPTION: " << e.what() << endl;
	}

	return 0;
}
