// BlueRedFileFormating.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void doTheThing(ifstream& rFile) {


    string lvlPathPending = "./pending_level/";
    string lvlPathFormated = "./formated_level/level";
    int lvlProgress = 1;
    string lvlExtension = ".txt";

    // read file
    int minY = 20;
    int maxY = 0;
    int minX = 20;
    int maxX = 0;

    int readGrid[20][20];
    int writeGrid[20][20];
    int buffer;
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            rFile >> readGrid[x][y];
            if (readGrid[x][y] != 1) {
                if (x > maxX) maxX = x;
                if (x < minX) minX = x;
                if (y > maxY) maxY = y;
                if (y < minY) minY = y;
            }
            writeGrid[x][y] = 1;
        }
    }
    int sizeX = (maxX - minX) + 2;
    int sizeY = (maxY - minY) + 2;
    rFile.close();

    // adjust grid
    int deltaX = minX - 1;
    int deltaY = minY - 1;
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            writeGrid[x][y] = readGrid[x + deltaX][y + deltaY];
        }
    }

    cout << "bruh\n";

    // find output file
    ifstream testFile;
    bool noExit = true;
    do {

        //testFile(lvlPathFormated + to_string(lvlProgress) + lvlExtension);
        string lvlToLoad = lvlPathFormated + to_string(lvlProgress) + lvlExtension;
        testFile.open(lvlToLoad); // open file
        if (testFile.is_open()) {
            testFile.close();
            cout << lvlPathFormated << to_string(lvlProgress) << lvlExtension << " found\n";

            lvlProgress++;
        }
        else {
            noExit = false;
        }

    } while (noExit);
    cout << "exit level count: " << lvlProgress << endl;

    // write output file
    ofstream oFile;
    oFile.open(lvlPathFormated + to_string(lvlProgress) + lvlExtension);
    if (oFile.is_open()) {
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                oFile << writeGrid[x][y] << " ";
            }
            oFile << endl;
        }
        oFile << sizeX << " " << sizeY;
        oFile.close();
    }

}
int main()
{

    ifstream rFile;
    string lvlPathPending = "./pending_level/";
    string lvlPathFormated = "./formated_level/level";
    int lvlProgress = 1;
    string lvlExtension = ".txt";

    while (false) {
        std::cout << "file name:\n";
        string fileName;
        cin >> fileName;

        // get file name
        string lvlToLoad = lvlPathPending + fileName + lvlExtension;

        // open file
        rFile.open(lvlToLoad);
        if (rFile.is_open()) {
            break;
        }
        else {
            cout << "failed to load file: " << lvlPathPending << fileName << lvlExtension << endl;
        }

        
    }

    bool noExit = true;
    do {

        //testFile(lvlPathFormated + to_string(lvlProgress) + lvlExtension);
        string lvlToLoad = lvlPathPending + "level" + to_string(lvlProgress) + lvlExtension;
        rFile.open(lvlToLoad); // open file
        if (rFile.is_open()) {
            doTheThing(rFile);
            rFile.close();
            cout << lvlPathPending << "level" << to_string(lvlProgress) << lvlExtension << " found\n";

            lvlProgress++;
        }
        else {
            noExit = false;
        }

    } while (noExit);
    
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
