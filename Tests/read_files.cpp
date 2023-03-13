//
// Created by gpinto03 on 13-03-2023.
//

#include "read_files.h"

void read_files::read_network(vector<Network> networks) {
    string stationA;
    string stationB;
    int capacity;
    string service;
    string dummy;

    ifstream input;
    input.open("../dataset/network.csv");
    if (input.is_open()) {
        getline(input, dummy);
        string l;
        getline(input, l);
        while (input >> stationA >> stationB >> capacity >> service) {
            cout << l << endl;
            Network network(stationA, stationB, capacity, service);
            networks.push_back(network);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
}

void read_files::print_networks(vector<Network> networks) {
    for (auto &i : networks) {
        cout << i.get_stationA() << ", " << i.get_stationB() << ", " << i.get_capacity() << ", " << i.get_service() << endl;
    }
}

void read_files::read_stations(vector<Station> stations) {

}

