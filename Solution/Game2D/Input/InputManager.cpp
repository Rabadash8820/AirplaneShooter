#include "InputManager.h"

#include <SFML\Window\Event.hpp>

using namespace Game2D;
using namespace sf;
using namespace std;

// INTERFACE
void InputManager::handleEvent(const Event& e, queue<Command>& commands) const {
	switch (e.type) {
	case Event::KeyPressed:
	case Event::KeyReleased:
		handleKeyboardEvent(e.key, commands);
		break;

	case Event::MouseButtonPressed:
	case Event::MouseButtonReleased:
	case Event::MouseMoved:
	case Event::MouseWheelMoved:
	case Event::MouseWheelScrolled:
		handleMouseEvent(e, commands);
		break;

	case Event::JoystickButtonPressed:
	case Event::JoystickButtonReleased:
	case Event::JoystickConnected:
	case Event::JoystickDisconnected:
	case Event::JoystickMoved:
		handleJoystickEvent(e, commands);
		break;
	}
}

// HELPER FUNCTIONS
void InputManager::handleKeyboardEvent(const Event::KeyEvent& key, queue<Command>&) const {}
void InputManager::handleMouseEvent(const Event& e, queue<Command>&) const {}
void InputManager::handleJoystickEvent(const Event& e, queue<Command>&) const {}
