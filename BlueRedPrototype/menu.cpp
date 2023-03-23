
#include "menu.h"
#include "maploader.h"
#include "mapgrid.h"
#include "gamemanager.h"

void MENU::menu(InputManager* inMng) {
    inputManager = inMng;
    while (choice1 != '3') {

        choice2 = 0;
        mainMenu();

        if (choice1 == '1') {
            system("CLS");
            PlaySound(TEXT("cyborg-ninja.wav"), NULL, SND_FILENAME | SND_ASYNC);
            GameManager gameWindow(inputManager);
            char inputchar = 0;
            while (inputchar != 27) {
                inputchar = inputManager->getInput();
                gameWindow.gameUpdate(inputchar);
            }
            inputManager->stopThreads();
            
            //stop the beat
            PlaySound(NULL, NULL, SND_PURGE);
        }

        if (choice1 == '2') {
            options();

        }

        if (choice1 == '3') {
            break;
        }
    }
}

void MENU::options(void) {



    while (choice2 != '3') {
        optionsMenu();

        if (choice2 != 27) {
            system("CLS");
            PlaySound(TEXT("cyborg-ninja.wav"), NULL, SND_FILENAME | SND_ASYNC);
            GameManager gameWindow(choice2, inputManager);
            gameWindow.levelSet(choice2-'1');
            char inputchar = 0;
            while (inputchar != 27) {
                inputchar = inputManager->getInput();
                gameWindow.gameUpdate(inputchar);
            }
            inputManager->stopThreads();
            
            //stop the beat
            PlaySound(NULL, NULL, SND_PURGE);
        }

        if (choice2 == 27) {
            break;
        }
    }
}

void MENU::mainMenu(void) {
    system("CLS");
    cout << "Main Menu\n";
    cout << "1 - Start new game\n";
    cout << "2 - Choose a map\n";
    cout << "3 - Quit (looser)\n";
    cout << "Please choose: ";
    choice1 = _getch();

}

void MENU::optionsMenu(void) {
    system("CLS");
    cout << "Level Menu\n";
    cout << "Entrer the number of the level\n";
    cout << "Please choose: ";
    choice2 = _getch();

}