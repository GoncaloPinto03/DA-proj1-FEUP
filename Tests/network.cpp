//
// Created by gpinto03 on 13-03-2023.
//

#include "network.h"

string network::get_stationA() const {
    return stationA;
}

void network::set_stationA(string nStationA) {
    this->stationA = nStationA;
}

string network::get_stationB() const {
    return stationB;
}

void network::set_stationB(string nStationB) {
    this->stationB = nStationB;
}

int network::get_capacity() const {
    return capacity;
}

void network::set_capacity(int nCapacity) {
    this->capacity = nCapacity;
}

string network::get_service() const {
    return service;
}

void network::set_service(string nService) {
    this->service = nService;
}

network::network(string stationA, string stationB, int capacity, string service) {
    this->stationA = stationA;
    this->stationB = stationB;
    this->capacity = capacity;
    this->service = service;
}
