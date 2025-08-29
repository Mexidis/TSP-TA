#ifndef TSP_TA_CITY_H
#define TSP_TA_CITY_H

#include <string>

class City {
private:
    int id;
    std::string name;
    std::string country;
    int population;
    double latitude;
    double longitude;

public:
    City();
    City(int id, const std::string& name, const std::string& country,
         int population, double latitude, double longitude);

    int getId() const;
    std::string getName() const;
    std::string getCountry() const;
    int getPopulation() const;
    double getLatitude() const;
    double getLongitude() const;

};

#endif // TSP_TA_CITY_H
