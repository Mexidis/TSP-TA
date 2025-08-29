#include <iostream>
#include "City.h"

int main() {
    City myCity(1, "Zac", "Mx", 15, 19230.34, 12321.4231);

    std::cout << "City: " << myCity.getName()
              << " (" << myCity.getCountry() << ")"
              << " with ID " << myCity.getId()
              << " in coordinates " << myCity.getLatitude()
              <<" : "<< myCity.getLongitude() <<std::endl;

    return 0;
}
