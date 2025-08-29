#include "City.h"

City::City() : id(0), population(0), latitude(0.0), longitude(0.0) {}

City::City(int id, const std::string& name, const std::string& country,
           int population, double latitude, double longitude)
    : id(id), name(name), country(country),
      population(population), latitude(latitude), longitude(longitude) {}

int City::getId() const {
    return id;
}

std::string City::getName() const {
    return name;
}

std::string City::getCountry() const {
    return country;
}

int City::getPopulation() const {
    return population;
}
double City::getLatitude() const {
    return latitude;
}
double City::getLongitude() const {
    return longitude;
}
