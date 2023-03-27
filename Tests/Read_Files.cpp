#include "Read_Files.h"

void Read_Files::read_networks(vector<Network> networks) {
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
            networks.push_back(network);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    networks.pop_back();
}

void Read_Files::print_networks(vector<Network> networks) {
    for (auto &i : networks) {
        cout << i.get_stationA() << ", " << i.get_stationB() << ", " << i.get_capacity() << ", " << i.get_service() << endl;
    }
}

void Read_Files::read_stations(vector<Station> stations) {
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
            stations.push_back(station);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    stations.pop_back();
}

void Read_Files::print_stations(vector<Station> stations) {
    for (auto &i : stations) {
        cout << i.get_name() << ", " << i.get_district() << ", " << i.get_municipality() << ", " << i.get_township() << ", " << i.get_line() << endl;
    }
}

