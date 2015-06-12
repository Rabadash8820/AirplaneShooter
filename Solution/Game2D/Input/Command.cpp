#include "Command.h"

using namespace Game2D;

Command::Command() {
	Category = (new Categories())->Nothing();
}