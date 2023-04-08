#ifndef PROJ1_MENU_H
#define PROJ1_MENU_H
#include "vector"
#include "string"
#include "Network.h"
#include "Station.h"
#include "Manager.h"
using namespace std;

class Menu {
private:
    vector<string> menuOptions = {"Basic Service Metrics", "Operation Cost Optimization", "Reliability and Sensitivity to Line Failures", "Exit"};
    vector<string> algOptions = {"Maximum number of trains that can simultaneously travel between two specific stations", "Work in progress 2", "Work in progress 3", "Exit"};
    int state = 0;
    void algoOptions(); //Displays secondary menu with algorithm options
    void mainMenu(); //Displays main menu
    void first(vector<Network> &packages, vector<Station> &stations); //Runs the first scenario
    void second(vector<Network> &packages, vector<Station> &stations); //Runs the second scenario
public:
    bool nextState(vector<Network> &packages, vector<Station> &stations); //Helps conecting the main function and the rest of the program
};

#endif //PROJ1_MENU_H