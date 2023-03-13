//
// Created by gpinto03 on 13-03-2023.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef PROJ1_NETWORK_H
#define PROJ1_NETWORK_H


class network {
public:
    string get_stationA() const;
    void set_stationA(string nStationA);
    string get_stationB() const;
    void set_stationB(string nStationB);
    int get_capacity() const;
    void set_capacity(string nCapacity);
    string get_service() const;
    void set_service(string nService);

    network( string stationA, string stationB, int capacity, string service);
private:
    string stationA;
    string stationB;
    int capacity;
    string service;
};


#endif //PROJ1_NETWORK_H
