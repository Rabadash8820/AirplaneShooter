#pragma once

#include "State.h"
#include "StateId.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include <map>
#include <functional>

namespace Game2D {

	class StateManager : private sf::NonCopyable {
		// ABSTRACT DATA TYPES
	public:
		enum Action {
			Push,
			Pop,
			Clear,
		};
	private:
		struct PendingChange {
			Action action;
			StateId stateId;
		};

		// PRIVATE VARIABLES
	private:
		std::vector<State::Ptr> _stack;
		std::vector<PendingChange> _pendingChanges;
		State::Context _context;
		std::map<unsigned int, std::function<State::Ptr()>> _factories;

		// INTERFACE
	public:
		explicit StateManager(State::Context context);
		template<typename StateClass>
		void registerState(StateId);
		void update(sf::Time);
		void draw();
		void handleEvent(const sf::Event&);
		void push(StateId);
		void pop();
		void clear();
		bool isEmpty() const;

		// HELPER FUNCTIONS
	private:
		State::Ptr createState(StateId);
		void applyPendingChanges();
	};

}
