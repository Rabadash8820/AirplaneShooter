#include "AirplaneShooter.h"
#include <iostream>

using namespace std;
using namespace Shooter;

int main() {
	// Run the game
	try {
		AirplaneShooter game;
		game.run();
	}

	// Report any crashes to the console
	catch (exception& e) {
		cout << "EXCEPTION: " << endl
			 << "\t" << e.what() << endl;
	}

	return 0;
}
