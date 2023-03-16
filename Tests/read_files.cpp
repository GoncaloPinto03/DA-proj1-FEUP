//
// Created by gpinto03 on 13-03-2023.
//

#include "read_files.h"

void read_files::read_network(vector<Network>& networks) {
    ifstream input("../dataset/network.csv");
    if (!input.is_open()) {
        cout << "ERROR: Failed to open network file" << endl;
        return;
    }

    string dummy;
    getline(input, dummy); // Skip header row

    string stationA, stationB, service;
    int capacity;
    while (input >> stationA >> stationB >> capacity >> service) {
        Network network(stationA, stationB, capacity, service);
        networks.push_back(network);
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

