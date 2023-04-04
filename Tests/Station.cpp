
#include "Station.h"

Station::Station(){}

Station::Station(
        const std::string& name,
        const std::string& district,
        const std::string& municipality,
        const std::string& township,
        const std::string& line
): name(name), district(district), municipality(municipality), township(township), line(line) {}

std::string Station::get_name() const {
    return this->name;
}

std::string Station::get_district() const {
    return this->district;
}

std::string Station::get_municipality() const {
    return this->municipality;
}

std::string Station::get_township() const {
    return this->township;
}

std::string Station::get_line() const {
    return this->line;
}

bool Station::operator==(const Station& other) const {
    return this->name == other.name;
}