//
// Created by pac61 on 31/08/2025.
//

#ifndef TSP_TA_PATH_H
#define TSP_TA_PATH_H
#include "City.h"


class Path
{
private:
        City origin;
        City destination;
        double weigth;
public:
        Path(City origin, City destination, double weigth);
        City getOrigin() const;
        City getDestination() const;
        double getWeigth() const;
        void setOrigin(City new_origin);
        void setDestination(City new_destination);
        void setWeigth(double new_weigth);
};


#endif //TSP_TA_PATH_H