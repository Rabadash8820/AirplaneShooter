#pragma once

#include <States\State.h>
#include <States\StateManager.h>

namespace Shooter {

	class SettingsState : public Game2D::State {
	public:
		SettingsState(Game2D::StateManager&, Context);
	};

}
