#pragma once

#include "..\GAME2D_API.h"

#include <SFML\System\Thread.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\System\Mutex.hpp>
#include <SFML\System\Time.hpp>

namespace Game2D {

	class GAME2D_API ParallelTask {
		// ENCAPSULATED FIELDS
	private:
		sf::Thread _thread;
		bool _finished;
		sf::Clock _elapsedTime;
		sf::Mutex _mutex;

		// INTERFACE
	public:
		ParallelTask();
		virtual float getProgress() = 0;
		void execute();
		bool isFinished();
		sf::Time getElapsedTime();

		// HELPER FUNCTIONS
	protected:
		virtual void doWork() = 0;
	private:
		void runTask();
	};

}
