#include "ParallelTask.h"

#include <SFML\System\Lock.hpp>

using namespace Game2D;
using namespace sf;

// INTERFACE
ParallelTask::ParallelTask() :
	_finished(false),
	_thread(&ParallelTask::runTask, this)
{ }
void ParallelTask::execute() {
	// Reset timer and call runTask() on the new Thread
	_elapsedTime.restart();
	_thread.launch();
}
bool ParallelTask::isFinished() {
	Lock lock(_mutex);
	return _finished;
}
Time ParallelTask::getElapsedTime() {
	return _elapsedTime.getElapsedTime();
}

// HELPER FUNCTIONS
void ParallelTask::runTask() {
	// Do whatever work a derived task has defined
	doWork();

	// Set the finished flag to true
	// in a separate scope to allow shorter lock
	{
		Lock lock(_mutex);
		_finished = true;
	}
}
