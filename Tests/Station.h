#include <iostream>
#include <string>
using namespace std;
#ifndef PROJ1_STATION_H
#define PROJ1_STATION_H

class Station {
public:
    Station();
    Station(string name, string district, string municipality, string township, string line);

    string get_name() const;
    string get_district() const;
    string get_municipality() const;
    string get_township() const;
    string get_line() const;
    void set_name(string nName);
    void set_district(string nDistrict);
    void set_municipality(string nMunicipality);
    void set_township(string nTownship);
    void set_line(string nLine);

private:
    string name;
    string district;
    string municipality;
    string township;
    string line;
};

#endif //PROJ1_STATION_H
