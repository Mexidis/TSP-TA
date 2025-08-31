#include <iostream>
#include "City.h"

int main()
{
        City myCity(1, "Zac", "Mx", 19230.34, 12321.4231);
        City city2(2, "Jerez", "Mx", 19230.34, 12321.4231);

        std::cout << myCity.distance(city2) << std::endl;

        // std::cout << "City: " << myCity.getName()
        //         << " (" << myCity.getCountry() << ")"
        //         << " with ID " << myCity.getId()
        //         << " in coordinates " << myCity.getLatitude()
        //         << " : " << myCity.getLongitude() << std::endl;

        return 0;
}
