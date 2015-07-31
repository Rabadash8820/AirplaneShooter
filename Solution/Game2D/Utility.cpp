#include "Utility.h"

using namespace Game2D;
using namespace std;
using namespace sf;

Utility::Utility() {}

string Utility::currentWorkingDirectory() {
	char currDir[FILENAME_MAX];
	GetCurrentDir(currDir, sizeof(currDir));
	// TO DO: Make some assertion here...
	return currDir;
}
void Utility::centerOrigin(Sprite& sprite) {
	FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(
		floor(bounds.left + bounds.width / 2.f),
		floor(bounds.top + bounds.height / 2.f));
}
void Utility::centerOrigin(Text& text) {
	FloatRect bounds = text.getLocalBounds();
	text.setOrigin(
		floor(bounds.left + bounds.width / 2.f),
		floor(bounds.top + bounds.height / 2.f));
}
