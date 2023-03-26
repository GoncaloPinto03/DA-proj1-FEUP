#include <iostream>
#include "read_files.h"
#include "Menu.h"

int main() {
    vector<Network> networks;
    vector<Station> stations;
    read_files::read_networks(networks);
    read_files::read_stations(stations);
    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(networks, stations);
    }
    return 0;
}