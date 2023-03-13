//
// Created by gpinto03 on 13-03-2023.
//

#include "Station.h"

string Station::get_name() const {
    return name;
}

void Station::set_name(string nName) {
    this->name = nName;
}

string Station::get_district() const {
    return district;
}

void Station::set_district(string nDistrict) {
    this->district = nDistrict;
}

string Station::get_municipality() const {
    return municipality;
}

void Station::set_municipality(string nMunicipality) {
    this->municipality = nMunicipality;
}

string Station::get_township() const {
    return township;
}

void Station::set_township(string nTownship) {
    this->township = nTownship;
}

string Station::get_line() const {
    return line;
}

void Station::set_line(string nLine) {
    this->line = nLine;
}

Station::Station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}

