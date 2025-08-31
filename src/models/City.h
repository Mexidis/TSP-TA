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
        double getLatitude() const;
        double getLongitude() const;
        void setId(int id);
        void setName(const std::string& name);
        void setCountry(const std::string& country);
        void setLatitude(double latitude);
        void setLongitude(double longitude);

};

#endif // TSP_TA_CITY_H
