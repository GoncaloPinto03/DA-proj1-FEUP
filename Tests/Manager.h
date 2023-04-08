#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Station.h"
#include "Network.h"
#include "../data_structures/Graph.h"
using namespace std;
#ifndef PROJ1_READ_FILES_H
#define PROJ1_READ_FILES_H

class Manager {
public:
    Manager();
    Graph graph;

    void read_networks(vector<Network> &networks);
    void read_stations(vector<Station> &stations);
    void print_networks(vector<Network> networks);
    void print_stations(vector<Station> stations);
    int maxTrainBetweenStations();
    int maxTrainBetweenStationsPairs();
};

#endif //PROJ1_READ_FILES_H
