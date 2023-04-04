#include <iostream>
#include <string>
using namespace std;
#ifndef PROJ1_STATION_H
#define PROJ1_STATION_H

class Station {
public:
public:

    Station();

    Station(const string &name, const string &district, const string &municipality, const string &township,
            const string &line);

/**
     * @brief Get the station name
     *
     * @return std::string stationName
     */
    std::string get_name() const;

    /**
     * @brief Get the station district
     *
     * @return std::string stationDistrict
     */
    std::string get_district() const;

    /**
     * @brief Get the station municipality
     *
     * @return std::string stationMunicipality
     */
    std::string get_municipality() const;

    /**
     * @brief Get the station township
     *
     * @return std::string stationTownship
     */
    std::string get_township() const;

    /**
     * @brief Get the stationLine
     *
     * @return std::string stationLine
     */
    std::string get_line() const;

    /**
     * @brief Checks stations equality
     *
     * @param other station
     * @return true are the same station
     * @return false are not the same station
     */
    bool operator==(const Station& other) const;




private:
    string name;
    string district;
    string municipality;
    string township;
    string line;
};

#endif //PROJ1_STATION_H
