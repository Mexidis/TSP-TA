#ifndef TSP_TA_CITY_H
#define TSP_TA_CITY_H

#include <memory>
#include <string>

class City
{
private:
        int id;
        std::string name;
        std::string country;
        double latitude;
        double longitude;
        double calculate_A(double, double, double, double);

public:
        City();
        City(int id, const std::string& name, const std::string& country,
                double latitude, double longitude);
        City(int id, const std::string& name, double latitude, double longitude);

        double distance(const City& other_city);

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
