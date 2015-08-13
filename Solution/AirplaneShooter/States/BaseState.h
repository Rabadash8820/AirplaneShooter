#pragma once

#include "Context.h"

#include <States\State.h>
#include <States\StateManager.h>

namespace Shooter {

	class BaseState : public Game2D::State {
		// INTERFACE
	public:
		BaseState(Game2D::StateManager& manager) :
			Game2D::State(manager)
		{ }
		virtual ~BaseState() { }

		// HELPER FUNCTIONS
	protected:
		const Context& getContext() const {
			const Context& context = static_cast<const Context&>(Game2D::State::getContext());
			return context;
		}
	};

}
