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
    manager.read_stations(stations);
    manager.read_networks(networks);

    Graph graph = manager.graph;

    //manager.maxTrainBetweenStations();
    //manager.maxTrainBetweenStationsPairs();

        string station;
        cout << "Qual é a estação?" << endl;
        getline(cin,station);


        int re = manager.maxTrainsArrivingAtStation(station);
        cout << re << endl;


    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(networks, stations);
    }

    return 0;
}

