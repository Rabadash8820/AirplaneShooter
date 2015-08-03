#include "InputManager.h"

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
void InputManager::handleEvent(const Event& e, queue<Command>& commands) const {
	switch (e.type) {
		// Handle keyboard events
	case Event::KeyPressed:
		handleKeyPress(e.key, commands);
		break;
	case Event::KeyReleased:
		handleKeyRelease(e.key, commands);
		break;

		// Handle mouse events
	case Event::MouseButtonPressed:
		handleMousePress(e.mouseButton, commands);
		break;
	case Event::MouseButtonReleased:
		handleMouseRelease(e.mouseButton, commands);
		break;
	case Event::MouseMoved:
		handleMouseMove(e.mouseMove, commands);
		break;
	case Event::MouseWheelScrolled:
		handleMouseScroll(e.mouseWheelScroll, commands);
		break;

		// Handle joystick events
	case Event::JoystickButtonPressed:
		handleJoystickPress(e.joystickButton, commands);
		break;
	case Event::JoystickButtonReleased:
		handleJoystickRelease(e.joystickButton, commands);
		break;
	case Event::JoystickConnected:
		handleJoystickConnect(e.joystickConnect, commands);
		break;
	case Event::JoystickDisconnected:
		handleJoystickDisconnect(e.joystickConnect, commands);
		break;
	case Event::JoystickMoved:
		handleJoystickMove(e.joystickMove, commands);
		break;
	}
}
