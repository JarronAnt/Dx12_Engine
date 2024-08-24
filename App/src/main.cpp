
#include "App.h"

int main() {
	
	using namespace Engine;
	App engineApp;

	//run the engine
	if (engineApp.init()) {
		while (engineApp.isRunning()) {
			engineApp.update();
		}
	}
	return 0;
}
