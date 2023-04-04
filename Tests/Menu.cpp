#include <limits>
#include "Menu.h"
#include "Auxiliar.h"

void Menu::mainMenu() {
    title("Main Menu");
    showMenu(menuOptions);

    int key = getInt("Choose an option");
    while (key < 1 || key > 10) key = getInt("Not a valid option. Choose a valid option.");
    if (key == 2) state = 1;
    else state = 5;
}

bool Menu::nextState(vector<Network> &networks, vector<Station> &stations) {
    clearSCR();
    switch (state) {
        case 0:
            mainMenu();
            return true;
        case 1:
            algoOptions();
            return true;
        case 2:
            first(networks, stations);
            state = 5;
            return true;
        case 3:
            second(networks, stations);
            state = 5;
            return true;
        default:
            return false;
    }}

void Menu::algoOptions() {
    title("Choose a process:");
    showMenu(algOptions);

    int key = getInt("Choose an option");
    while (key<1 || key>5){
        key = getInt("Not a valid option. Choose a valid option.");
    }

    switch (key) {
        case 1:
            state = 2;
            break;
        case 2:
            state = 3;
            break;
        case 3:
            state = 4;
            break;
        default:
            state = 5;
    }
}

void Menu::first(vector<Network> &networks, vector<Station> &stations) {
    //vector<int> final = firstScenario(networks, stations); - Colocar valores do output
    //Colocar aqui as definições das variaveis que forem precisas e iniciar o output, aka os cout com os resultados
    cout << "| Thanks for using our program!" << endl;
    cout << "| Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void Menu::second(vector<Network> &networks, vector<Station> &stations) {
    //vector<int> final = secondScenario(networks, stations); - Colocar valores do output
    //Colocar aqui as definições das variaveis que forem precisas e iniciar o output, aka os cout com os resultados
    cout << "| Thanks for using our program!" << endl;
    cout << "| Click Enter!";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}