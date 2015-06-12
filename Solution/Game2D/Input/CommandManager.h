#pragma once

#include "Command.h"
#include <queue>

namespace Game2D {

	class CommandManager {
		// VARIABLES
	private:
		std::queue<Command> _queue;

		// CONSTRUCTORS / DESTRUCTOR
	public:
		CommandManager();
		~CommandManager();

		// INTERFACE
	public:
		void push(const Command& Command);
		Command pop();
		bool isEmpty() const;

	};

}