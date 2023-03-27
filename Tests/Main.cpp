#include <iostream>
#include "Network.h"
#include "Station.h"
#include "Read_Files.h"
#include "../data_structures/Graph.h"
#include "../data_structures/Heap.h"
#include "../data_structures/MutablePriorityQueue.h"
#include "../data_structures/UFDS.h"
#include "../data_structures/VertexEdge.h"
#include <vector>
using namespace std;


int main() {
    vector<Network> networks;
    Read_Files::read_networks(networks);
    vector<Station> stations;
    Read_Files::read_stations(stations);

    // create Graph
    Graph graph;
    int n = 1;
    for (auto i : stations) {

    }




    return 0;
}

