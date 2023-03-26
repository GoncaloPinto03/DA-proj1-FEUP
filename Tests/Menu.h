#ifndef PROJ1_MENU_H
#define PROJ1_MENU_H
#include "vector"
#include "string"
#include "Network.h"
#include "Station.h"
#include "read_files.h"
using namespace std;

class Menu {
private:
    vector<string> menuOptions = {"Basic Service Metrics", "Operation Cost Optimization", "Reliability and Sensitivity to Line Failures", "Exit"};
    vector<string> algOptions = {"Deliver more packages with the least amount of stations", "Make the most profit", "Deliver express packages", "Exit"};
    int state = 0;
    void algoOptions(); //Displays secondary menu with algorithm options
    void mainMenu(); //Displays main menu
    void first(vector<Network> &packages, vector<Station> &stations); //Runs the first scenario
    void second(vector<Network> &packages, vector<Station> &stations); //Runs the second scenario
public:
    bool nextState(vector<Network> &packages, vector<Station> &stations); //Helps connecting the main function and the rest of the program
};

#endif //PROJ1_MENU_H
