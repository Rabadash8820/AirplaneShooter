#include "ParallelTask.h"

using namespace Game2D;

// INTERFACE
ParallelTask::ParallelTask() {}
float ParallelTask::getProgress() {
	return 0.f;
}
void ParallelTask::execute() {

}
bool ParallelTask::isFinished() {
	return false;
}
