#include "CommandManager.h"

using namespace Game2D;

// CONSTRUCTORS / DESTRUCTOR
CommandManager::CommandManager() {}
CommandManager::~CommandManager() {}

// INTERFACE
void CommandManager::push(const Command& Command) {

}
Command CommandManager::pop() {
	return Command();
}
bool CommandManager::isEmpty() const {
	return _queue.empty();
}