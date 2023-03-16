#include "inputmanager.h"

//bool SendToSerial(SerialPort* arduino, json j_msg);
//bool RcvFromSerial(SerialPort* arduino, string& msg);

SerialPort* arduino; //doit etre un objet global!

InputManager::InputManager() {
    //arduino = nullptr;
    isActiveController = false;
    isActiveKeyboard = false;
    // --------------------------- connect controller
    string comPort = "COM1";
    for (int i = '1'; i <= '9'; i++) {
        comPort[3] = i;
        arduino = new SerialPort(comPort.c_str(), BAUD);
        if (arduino->isConnected()) {
            //isActiveController = true;
            break;
        }
        else {
            delete arduino;
            //arduino = nullptr;
        }
    }

    startThreads();
}
InputManager::~InputManager() {
    stopThreads();
}

char InputManager::getInput() {

    char returnVal = 0;
    threadLock.lock();
    if (pendingInput.size() > 0) {
        returnVal = pendingInput.front();
        pendingInput.pop();
    }
    threadLock.unlock();
    return returnVal;
}


void InputManager::startThreads() {
    if (!isActiveKeyboard) {
        isActiveKeyboard = true;
        keyboardComs = thread(&InputManager::readKeyboard, this);
    }
    if (!isActiveController) {
        isActiveController = true;
        controllerComs = thread(&InputManager::readController, this);
    }
    
}

bool InputManager::stopThreads() {
    if (isActiveKeyboard) {
        isActiveKeyboard = false;
        keyboardComs.join();
    }
    if (isActiveController) {
        isActiveController = false;
        controllerComs.join();
    }
    return true;

}


void InputManager::readKeyboard() {
	char inputchar = 0;
	while (isActiveKeyboard) {
		inputchar = _getch();

		threadLock.lock();
		if (pendingInput.size() < 5) {
			pendingInput.push(inputchar);
		}
		threadLock.unlock();
	}
}


void InputManager::readController() {
    char inputchar = 0;
    while (isActiveController) {
        
        // skip loop if serial port is empty
        if (!recieveComs()) {
            continue;
        }

        std::list<char> newInput(decodeController());

        threadLock.lock();
        for (char c : newInput) {
            if (c != 0) {
                pendingInput.push(c);
            }
        }
        threadLock.unlock();
        /*
        threadLock.lock();
        //decode the JSON into variables
        // -----------------------------example
        int tempExample = -1;
        if (!comsIn["movement"].is_null()) {
            tempExample = comsIn["movement"];
            //tempExample = comsIn["mouvment"].get<int>(); // read json field
        }
        // -----------------------------example end
        

        if (pendingInput.size() < 5) {
            pendingInput.push(inputchar);
        }
        threadLock.unlock();
        */
    }
}

bool InputManager::recieveComs() {

    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];

    int buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    
    if (buffer_size > 0) {
        str_buffer.assign(char_buffer, buffer_size);
        comsIn.clear();
        comsIn = json::parse(str_buffer);
        return true;
    } else {
        return false;
    }
}


std::list<char> InputManager::decodeController() {
    std::list<char> inputList;
    int activePlayer;
    activePlayer = comsIn["act"];
    
    if (activePlayer == 0) {
        inputList.push_back(buttonPress(comsIn["rst"], controllerState.reload, 'r'));
        inputList.push_back(buttonPress(
            int(comsIn["dir"]) == 1,
            controllerState.up,
            'i'
        ));
        inputList.push_back(buttonPress(
            int(comsIn["dir"]) == 2,
            controllerState.down,
            'k'
        ));
        inputList.push_back(buttonPress(
            int(comsIn["dir"]) == 3,
            controllerState.right,
            'l'
        ));
        inputList.push_back(buttonPress(
            int(comsIn["dir"]) == 4,
            controllerState.left,
            'h'
        ));
    }
    else {

    }
    return inputList;
}


char InputManager::buttonPress(int recivedState, bool& buttonState, char map) {
    
    if (recivedState == 1 && buttonState == ARMED) {
        buttonState = ACTIVE;
        return map;
    }
    else if (recivedState == 0) {
        buttonState = ARMED;
    }
    return 0;
}

void InputManager::getLevel(int niveau) {
    level = niveau;
}


/*
//----------------------------- Fonction "Main" -----------------------------
int main() {
    

    string raw_msg;
    // Structure de donnees JSON pour envoie et reception
    int led_state = 1;
    json j_msg_send, j_msg_rcv;

    // Boucle pour tester la communication bidirectionnelle Arduino-PC
    for (int i = 0; true; i++) {
        // Envoie message Arduino
        j_msg_send["led"] = led_state;
        if (!SendToSerial(arduino, j_msg_send)) {
            cerr << "Erreur lors de l'envoie du message. " << endl;
        }
        // Reception message Arduino
        j_msg_rcv.clear(); // effacer le message precedent
        if (!RcvFromSerial(arduino, raw_msg)) {
            cerr << "Erreur lors de la reception du message. " << endl;
        }


        // Impression du message de l'Arduino si valide
        if (raw_msg.size() > 0) {
            //cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json
            j_msg_rcv = json::parse(raw_msg);

            int potentionmeter = 0;
            int buttonState = 0;
            potentionmeter = j_msg_rcv["analog"].get<int>();
            buttonState = j_msg_rcv["boutton"].get<int>();
            cout << "potentionmeter: " << potentionmeter << " boutton: " << buttonState << endl;
            //Serial.print("potentionmeter: \n");

            //cout << "Message de l'Arduino: " << j_msg_rcv << endl;

        }


        //Changement de l'etat led
        led_state = !led_state;

        // Bloquer le fil pour environ 1 sec
        Sleep(200); // 1000ms
    }
    return 0;
}

*/

/*
//---------------------------Definition de fonctions ------------------------
bool SendToSerial(SerialPort* arduino, json j_msg) {
    // Return 0 if error
    string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}
*/

/*
bool RcvFromSerial(SerialPort* arduino, string& msg) {

    // Message output in msg
    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string

    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    return true;
}
*/