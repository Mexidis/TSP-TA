//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_NEIGHBORHOOD_H
#define TSP_TA_NEIGHBORHOOD_H

#include "../models/Solution.h"

class Neighborhood {
        // generates a neighbor by exchanging two cities
        static Solution generateNeighbor(Solution& sol);
};


#endif //TSP_TA_NEIGHBORHOOD_H