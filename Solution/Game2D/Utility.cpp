#include "Utility.h"

#include <SFML\Graphics\Rect.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

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

std::string Utility::toString(Keyboard::Key key) {
	// A macro to return a string that looks exactly the same as the SFML Key enum
#define KEY_TO_STRING(KEY) case sf::Keyboard::KEY: return #KEY;

	// Convert the Key enum to a string
	switch (key) {
		KEY_TO_STRING(Unknown)
		KEY_TO_STRING(A)
		KEY_TO_STRING(B)
		KEY_TO_STRING(C)
		KEY_TO_STRING(D)
		KEY_TO_STRING(E)
		KEY_TO_STRING(F)
		KEY_TO_STRING(G)
		KEY_TO_STRING(H)
		KEY_TO_STRING(I)
		KEY_TO_STRING(J)
		KEY_TO_STRING(K)
		KEY_TO_STRING(L)
		KEY_TO_STRING(M)
		KEY_TO_STRING(N)
		KEY_TO_STRING(O)
		KEY_TO_STRING(P)
		KEY_TO_STRING(Q)
		KEY_TO_STRING(R)
		KEY_TO_STRING(S)
		KEY_TO_STRING(T)
		KEY_TO_STRING(U)
		KEY_TO_STRING(V)
		KEY_TO_STRING(W)
		KEY_TO_STRING(X)
		KEY_TO_STRING(Y)
		KEY_TO_STRING(Z)
		KEY_TO_STRING(Num0)
		KEY_TO_STRING(Num1)
		KEY_TO_STRING(Num2)
		KEY_TO_STRING(Num3)
		KEY_TO_STRING(Num4)
		KEY_TO_STRING(Num5)
		KEY_TO_STRING(Num6)
		KEY_TO_STRING(Num7)
		KEY_TO_STRING(Num8)
		KEY_TO_STRING(Num9)
		KEY_TO_STRING(Escape)
		KEY_TO_STRING(LControl)
		KEY_TO_STRING(LShift)
		KEY_TO_STRING(LAlt)
		KEY_TO_STRING(LSystem)
		KEY_TO_STRING(RControl)
		KEY_TO_STRING(RShift)
		KEY_TO_STRING(RAlt)
		KEY_TO_STRING(RSystem)
		KEY_TO_STRING(Menu)
		KEY_TO_STRING(LBracket)
		KEY_TO_STRING(RBracket)
		KEY_TO_STRING(SemiColon)
		KEY_TO_STRING(Comma)
		KEY_TO_STRING(Period)
		KEY_TO_STRING(Quote)
		KEY_TO_STRING(Slash)
		KEY_TO_STRING(BackSlash)
		KEY_TO_STRING(Tilde)
		KEY_TO_STRING(Equal)
		KEY_TO_STRING(Dash)
		KEY_TO_STRING(Space)
		KEY_TO_STRING(Return)
		KEY_TO_STRING(BackSpace)
		KEY_TO_STRING(Tab)
		KEY_TO_STRING(PageUp)
		KEY_TO_STRING(PageDown)
		KEY_TO_STRING(End)
		KEY_TO_STRING(Home)
		KEY_TO_STRING(Insert)
		KEY_TO_STRING(Delete)
		KEY_TO_STRING(Add)
		KEY_TO_STRING(Subtract)
		KEY_TO_STRING(Multiply)
		KEY_TO_STRING(Divide)
		KEY_TO_STRING(Left)
		KEY_TO_STRING(Right)
		KEY_TO_STRING(Up)
		KEY_TO_STRING(Down)
		KEY_TO_STRING(Numpad0)
		KEY_TO_STRING(Numpad1)
		KEY_TO_STRING(Numpad2)
		KEY_TO_STRING(Numpad3)
		KEY_TO_STRING(Numpad4)
		KEY_TO_STRING(Numpad5)
		KEY_TO_STRING(Numpad6)
		KEY_TO_STRING(Numpad7)
		KEY_TO_STRING(Numpad8)
		KEY_TO_STRING(Numpad9)
		KEY_TO_STRING(F1)
		KEY_TO_STRING(F2)
		KEY_TO_STRING(F3)
		KEY_TO_STRING(F4)
		KEY_TO_STRING(F5)
		KEY_TO_STRING(F6)
		KEY_TO_STRING(F7)
		KEY_TO_STRING(F8)
		KEY_TO_STRING(F9)
		KEY_TO_STRING(F10)
		KEY_TO_STRING(F11)
		KEY_TO_STRING(F12)
		KEY_TO_STRING(F13)
		KEY_TO_STRING(F14)
		KEY_TO_STRING(F15)
		KEY_TO_STRING(Pause)
	}
}

float Utility::toRadians(float degrees) {
	float radians = M_PI / 180.f * degrees;
	return radians;
}
float Utility::toDegrees(float radians) {
	float degrees = radians * 180.f / M_PI;
	return degrees;
}

Vector2f Utility::unitVector(Vector2f vector) {
	float x = vector.x, y = vector.y;
	float length = sqrtf(x*x + y*y);
	return vector * (1.f / length);
}
float Utility::distance(Vector2f first, Vector2f second) {
	float dx = first.x - second.x;
	float dy = first.y - second.y;
	float dist = sqrtf(dx*dx + dy*dy);
	return dist;
}
