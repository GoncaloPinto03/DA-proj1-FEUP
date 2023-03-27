#include <iostream>
#include <string>
using namespace std;
#ifndef PROJ1_NETWORK_H
#define PROJ1_NETWORK_H


class Network {
public:
    Network(string stationA, string stationB, int capacity, string service);

    string get_stationA() const;
    void set_stationA(string nStationA);
    string get_stationB() const;
    void set_stationB(string nStationB);
    int get_capacity() const;
    void set_capacity(int nCapacity);
    string get_service() const;
    void set_service(string nService);

private:
    string stationA;
    string stationB;
    int capacity;
    string service;
};


#endif //PROJ1_NETWORK_H
