#include <iostream>
#include "Network.h"
#include "Station.h"
#include "Manager.h"
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
    Manager manager = Manager();
    manager.read_networks(networks);
    manager.read_stations(stations);

    Graph graph = manager.graph;

    manager.maxTrainBetweenStations();
    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(networks, stations);
    }

    return 0;
}

