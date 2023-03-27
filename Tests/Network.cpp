#include "Network.h"

Network::Network(string stationA, string stationB, int capacity, string service) {
    this->stationA = stationA;
    this->stationB = stationB;
    this->capacity = capacity;
    this->service = service;
}

string Network::get_stationA() const {
    return stationA;
}

void Network::set_stationA(string nStationA) {
    this->stationA = nStationA;
}

string Network::get_stationB() const {
    return stationB;
}

void Network::set_stationB(string nStationB) {
    this->stationB = nStationB;
}

int Network::get_capacity() const {
    return capacity;
}

void Network::set_capacity(int nCapacity) {
    this->capacity = nCapacity;
}

string Network::get_service() const {
    return service;
}

void Network::set_service(string nService) {
    this->service = nService;
}

