//
// Created by gpinto03 on 13-03-2023.
//

#include "main.h"
#include <iostream>
#include "read_files.h"

int main() {
    vector<Network> networks;
    read_files::read_networks(networks);
    vector<Station> stations;
    read_files::read_stations(stations);
    return 0;
}