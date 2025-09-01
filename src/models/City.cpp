#include "City.h"
#include <cmath>

City::City() : id(0), latitude(0.0), longitude(0.0)
{
}

City::City(int id, const std::string& name, const std::string& country, double latitude, double longitude)
        : id(id), name(name), country(country), latitude(latitude), longitude(longitude)
{
}

City::City(int id, const std::string& name, double latitude, double longitude)
        : id(id), name(name), country(country), latitude(latitude), longitude(longitude)
{

}

double City::distance(const City& other)
{
        const double R = 6373000.0;
        const double PI = 3.141592653589;

        double u_lat, u_long, v_lat, v_long;
        u_lat = getLatitude() * PI / 180.0;
        u_long = getLongitude() * PI / 180.0;
        v_lat = other.getLatitude() * PI / 180.0;
        v_long = other.getLongitude() * PI / 180.0;

        const double A = calculate_A(u_lat, v_lat, u_long, v_long);

        double C = 2 * atan2(sqrt(A), sqrt(1 - A));

        return C * R;
}

double City::calculate_A(double u_lat, double v_lat, double u_long, double v_long)
{

        double A = pow(sin((u_lat - v_lat) / 2), 2) +
                cos(u_lat) * cos(v_lat) * pow(sin((v_long - u_long) / 2), 2);
        return A;
}


int City::getId() const
{
        return id;
}

std::string City::getName() const
{
        return name;
}

std::string City::getCountry() const
{
        return country;
}

double City::getLatitude() const
{
        return latitude;
}

double City::getLongitude() const
{
        return longitude;
}

void City::setId(int id)
{
        this->id = id;
}

void City::setName(const std::string& name)
{
        this->name = name;
}

void City::setCountry(const std::string& country)
{
        this->country = country;
}

void City::setLatitude(double latitude)
{
        this->latitude = latitude;
}
void City::setLongitude(double longitude)
{
        this->longitude = longitude;
}
