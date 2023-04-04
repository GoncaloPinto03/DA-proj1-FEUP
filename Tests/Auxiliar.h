#ifndef PROJ1_AUXILIAR_H
#define PROJ1_AUXILIAR_H
#include "string"
#include "vector"

using namespace std;

void clearSCR(); //Clears the screen

void title(const string& string = ""); //Displays title

void showMenu(const vector<string>& options, int settingsOp = 0); //Displays menu options

int getInt(const string& text = "", const string& text2 = ""); //Gets the user's option as an integer

double getDouble(const string& text = "", const string& text2 = ""); //Gets the user's option as a double

#endif //PROJ1_AUXILIAR_H