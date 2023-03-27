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
    void set_name(string nName);
    string get_district() const;
    void set_district(string nDistrict);
    string get_municipality() const;
    void set_municipality(string nMunicipality);
    string get_township() const;
    void set_township(string nTownship);
    string get_line() const;
    void set_line(string nLine);

private:
    string name;
    string district;
    string municipality;
    string township;
    string line;
};


#endif //PROJ1_STATION_H
