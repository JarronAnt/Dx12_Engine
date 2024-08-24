
#include "App.h"

int main() {
	
	using namespace Engine;
	App engineApp;

	if (engineApp.init()) {
		while (engineApp.isRunning()) {
			engineApp.update();
		}
	}
	return 0;
}
