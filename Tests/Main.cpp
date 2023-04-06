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
    Manager manager;
    manager.read_networks(networks);
    manager.read_stations(stations);

    // create Graph
    int n = 1;
    for (auto i : stations) {
        manager.graph.addVertex(n, i.get_name(), i.get_district(), i.get_municipality(), i.get_township(), i.get_line());
    }
    cout << manager.graph.getNumVertex() << endl;
    int a, b;
    double cap;
    for (auto j : networks) {
        for (auto k : manager.graph.getVertexSet()) {
            if ((k->getName() == j.get_stationA()) && (k->getName() == j.get_stationB()))
                a = k->getId();
                b = k->getId();
                cap = j.get_capacity();
                break;
        }
    }
    manager.graph.addEdge(a, b, cap);

    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(networks, stations);
    }

    return 0;
}

