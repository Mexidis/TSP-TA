#include <iostream>
#include "City.h"

int main()
{
        City myCity(1, "NY", "EUA", 40.646, -73.777);
        City city2(2, "Paris", "FR", 49.01280, 2.55000);

        std::cout << city2.distance(myCity) << std::endl;

        // std::cout << "City: " << myCity.getName()
        //         << " (" << myCity.getCountry() << ")"
        //         << " with ID " << myCity.getId()
        //         << " in coordinates " << myCity.getLatitude()
        //         << " : " << myCity.getLongitude() << std::endl;

        return 0;
}
