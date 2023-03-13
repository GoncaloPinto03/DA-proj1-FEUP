//
// Created by gpinto03 on 13-03-2023.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef PROJ1_STATION_H
#define PROJ1_STATION_H


class station {
public:
    string get_name() const;
    void set_name(string nName);
    string get_district() const;
    void set_district(string nDistrict);
    string get_municipality() const;
    void set_municipality(string nMunicipality);
    string get_township() const;
    void set_township(string nTownship);
    string get_line() const;
    void set_line(string nLine);

    station(string name, string district, string municipality, string township, string line);
private:
    string name;
    string district;
    string municipality;
    string township;
    string line;
};


#endif //PROJ1_STATION_H
