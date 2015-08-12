#pragma once

#include "..\GAME2D_API.h"
#include "State.h"
#include "StateId.h"
#include "Context.h"

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include <vector>
#include <map>
#include <functional>

namespace Game2D {

	class GAME2D_API StateManager : private sf::NonCopyable {
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
		Context _context;
		std::map<StateId, std::function<State::Ptr()>> _factories;

		// INTERFACE
	public:
		explicit StateManager(Context& context);
		template<typename StateClass>
		void registerState(StateId id) {
			// Template member function must be defined inline 

			// Associate this Id with a factory method to produce the provided State class
			_factories[id] = [this]() {
				return State::Ptr(new StateClass(*this));
			};
		}
		void update(sf::Time);
		void draw();
		void handleEvent(const sf::Event&);
		void push(StateId);
		void pop();
		void clear();
		bool isEmpty() const;
		Context getContext() const;

		// HELPER FUNCTIONS
	private:
		State::Ptr createState(StateId);
		void applyPendingChanges();
	};

}
