#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Station.h"
#include "Network.h"
using namespace std;
#ifndef PROJ1_READ_FILES_H
#define PROJ1_READ_FILES_H



class Read_Files {
public:
    static void read_networks(vector<Network> networks);
    static void read_stations(vector<Station> stations);
    static void print_networks(vector<Network> networks);
    static void print_stations(vector<Station> stations);

};


#endif //PROJ1_READ_FILES_H
