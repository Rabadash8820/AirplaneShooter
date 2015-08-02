#pragma once

#include "..\GAME2D_API.h"

#include <SFML\System\Thread.hpp>

namespace Game2D {

	class GAME2D_API ParallelTask {
		// INTERFACE
	public:
		ParallelTask();
		float getProgress();
		void execute();
		bool isFinished();
	};

}
