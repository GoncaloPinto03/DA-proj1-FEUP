#include <iostream>
#include "Network.h"
#include "Station.h"
#include "Read_Files.h"
#include "Menu.h"
#include "../data_structures/Graph.h"
#include "../data_structures/Heap.h"
#include "../data_structures/MutablePriorityQueue.h"
#include "../data_structures/UFDS.h"
#include "../data_structures/VertexEdge.h"
#include <vector>
using namespace std;

int main() {
    vector<Network> networks;
    vector<Station> stations;
    Read_Files::read_networks(networks);
    Read_Files::read_stations(stations);
    Read_Files::print_networks(networks);

    // create Graph
    Graph graph;
    int n = 1;
    for (auto i : stations) {

    }

    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(networks, stations);
    }

    return 0;
}

