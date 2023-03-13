//
// Created by gpinto03 on 13-03-2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Station.h"
#include "Network.h"
using namespace std;
#ifndef PROJ1_READ_FILES_H
#define PROJ1_READ_FILES_H



class read_files {
public:
    static void read_network(vector<Network> networks);
    void read_stations(vector<Station> stations);
    static void print_networks(vector<Network> networks);
};


#endif //PROJ1_READ_FILES_H
