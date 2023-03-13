//
// Created by gpinto03 on 13-03-2023.
//

#include "station.h"

string station::get_name() const {
    return name;
}

void station::set_name(string nName) {
    this->name = nName;
}

string station::get_district() const {
    return district;
}

void station::set_district(string nDistrict) {
    this->district = nDistrict;
}

string station::get_municipality() const {
    return municipality;
}

void station::set_municipality(string nMunicipality) {
    this->municipality = nMunicipality;
}

string station::get_township() const {
    return township;
}

void station::set_township(string nTownship) {
    this->township = nTownship;
}

string station::get_line() const {
    return line;
}

void station::set_line(string nLine) {
    this->line = nLine;
}

station::station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}
