#include "Utility.h"

using namespace Game2D;
using namespace std;

Utility::Utility() {}

string Utility::currentWorkingDirectory() {
	char currDir[FILENAME_MAX];
	GetCurrentDir(currDir, sizeof(currDir));
	// TO DO: Make some assertion here...
	return currDir;
}
