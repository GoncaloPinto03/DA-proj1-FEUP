#include "Manager.h"

void Manager::read_networks(vector<Network> &networks) {
    string stationA;
    string stationB;
    string capacity_str;
    int capacity;
    string service;
    string dummy;

    ifstream input;
    input.open("../dataset/network.csv");
    if (input.is_open()) {
        getline(input, dummy);
        while (input.good()) {
            getline(input, stationA, ',');
            getline(input, stationB, ',');
            getline(input, capacity_str, ',');
            getline(input, service, '\n');

            capacity = stoi(capacity_str);
            Network network(stationA, stationB, capacity, service);
            graph.addBidirectionalEdge(stationA, stationB, capacity);
            networks.push_back(network);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    networks.pop_back();
}

void Manager::print_networks(vector<Network> networks) {
    for (auto &i : networks) {
        cout << i.get_stationA() << ", " << i.get_stationB() << ", " << i.get_capacity() << ", " << i.get_service() << endl;
    }
}

void Manager::read_stations(vector<Station> &stations) {
    string name;
    string district;
    string municipality;
    string township;
    string line;
    string dummy;

    ifstream input;
    input.open("../dataset/stations.csv");
    if (input.is_open()) {
        getline(input, dummy);
        while (input.good()) {
            getline(input, name, ',');
            getline(input, district, ',');
            getline(input, municipality, ',');
            getline(input, township, ',');
            getline(input, line, '\n');

            Station station(name, district, municipality, township, line);
            graph.addVertex(station);
            stations.push_back(station);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    stations.pop_back();
}

void Manager::print_stations(vector<Station> stations) {
    for (auto &i : stations) {
        cout << i.get_name() << ", " << i.get_district() << ", " << i.get_municipality() << ", " << i.get_township() << ", " << i.get_line() << endl;
    }
}

Manager::Manager() {

}

int Manager::maxTrainBetweenStations() {
    std::string station_a, station_b;

    std::cout << "Station A: " << endl;
    getline(std::cin >> ws , station_a);

    std::cout << "Station B: " << endl;
    getline(std::cin >> ws , station_b);

    int max_trains = graph.edmondsKarp2(station_a, station_b);

    std::cout << "Max number of trains between " << station_a << " and " << station_b << ": " << max_trains << "\n";

    return max_trains;
}

int Manager::maxTrainBetweenStationsPairs() {
    vector<pair<pair<string, string>, int>> max_pairs;
    int max_trains = 0;
    std::string v1;
    std::string v2;
    for (auto i : graph.getVertexSet()){
        for (auto j : graph.getVertexSet()){
            if (i != j) {
                int a = graph.edmondsKarp2(i->getStation().get_name(), j->getStation().get_name());
                for (auto v : graph.getVertexSet()) {
                    for (auto e : v->getAdj()) {
                        e->setFlow(0);
                    }
                }
                if (a > max_trains) {
                    max_pairs.clear();
                    max_pairs.emplace_back(std::make_pair(i->getStation().get_name(), j->getStation().get_name()), a);
                    max_trains = a;
                    v1 = i->getStation().get_name();
                    v2 = j->getStation().get_name();
                }
                else if (a == max_trains) {
                    max_trains = a;
                    max_pairs.emplace_back(std::make_pair(i->getStation().get_name(), j->getStation().get_name()), a);
                    v1 = i->getStation().get_name();
                    v2 = j->getStation().get_name();
                }
            }
        }
    }

    for (int i = 0; i < max_pairs.size(); i++) {
        std::cout << "Max number of trains between " << max_pairs[i].first.first << " and " << max_pairs[i].first.second << ": " << max_pairs[i].second << "\n";
    }
    return max_trains;
}

