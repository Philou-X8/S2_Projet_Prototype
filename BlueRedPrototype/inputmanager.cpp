#include "inputmanager.h"


InputManager::InputManager() {
	startThreads();
}
InputManager::~InputManager() {

}

void InputManager::startThreads() {
	//thread tr1(&InputManager::test1, this);
	//thread tr2(&InputManager::test2, this, 20);
	//tr1.join();
	//tr2.join();

	keyboardComs = thread(&InputManager::readKeyboard, this);
}
void InputManager::stopThreads() {
	keyboardComs.join();
	//tr1.join();
	//tr2.join();
}

void InputManager::test1() {
	threadLock.lock();
	cout << "test1 is running / param = " << 10 << endl;
	threadLock.unlock();
}
void InputManager::test2(int b) {
	threadLock.lock();
	cout << "test2 is running / param = " << b << endl;
	threadLock.unlock();
}


void InputManager::readKeyboard() {
	char inputchar = 0;
	while (inputchar != 27) {
		inputchar = _getch();

		threadLock.lock();
		pendingInput.push(inputchar);
		threadLock.unlock();
	}
}

char InputManager::getInput(){
	
	char returnVal = 0;
	threadLock.lock();
	if (pendingInput.size() > 0) {
		returnVal = pendingInput.front();
		pendingInput.pop();
		
	}
	threadLock.unlock();
	return returnVal;
}
