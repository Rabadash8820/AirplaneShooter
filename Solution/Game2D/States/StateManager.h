#pragma once

#include "..\GAME2D_API.h"
#include "State.h"
#include "Context.h"

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include <vector>

namespace Game2D {

	class GAME2D_API StateManager : private sf::NonCopyable {
		// ABSTRACT DATA TYPES
	public:
		enum class Action {
			Push,
			Pop,
			Clear,
		};
	private:
		struct PendingChange {
			PendingChange(Action a, State::Ptr s) :
				action(a),
				state(move(s))
			{ }
			PendingChange(PendingChange&& that) :
				action(that.action),
				state(move(that.state))
			{ }
			Action action;
			State::Ptr state;
		};

		// PRIVATE VARIABLES
	private:
		std::vector<State::Ptr> _stack;
		std::vector<PendingChange> _pendingChanges;
		Context _context;

		// INTERFACE
	public:
		explicit StateManager(Context& context);
		void update(sf::Time);
		void draw();
		void handleEvent(const sf::Event&);
		template<typename StateClass>
		void push() {
			_pendingChanges.push_back({
				Action::Push,
				std::move(State::Ptr(
					new StateClass(*this)))
			});
		}
		void pop();
		void clear();
		bool isEmpty() const;
		Context getContext() const;

		// HELPER FUNCTIONS
	private:
		void applyPendingChanges();
	};

}
