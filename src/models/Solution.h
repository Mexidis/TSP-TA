//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_SOLUTION_H
#define TSP_TA_SOLUTION_H
#include "Graph.h"
#include "City.h"
#include "CompleteGraph.h"

class Solution {
private:
        std::vector<City> route;

public:
        Solution(const std::vector<City>& cities);

        double length(const CompleteGraph& GS) const;   // sums weights in GS
        bool isFeasible(const Graph& G) const;          // do all the edges exist?
        const std::vector<City>& getRoute() const { return route; }
};


#endif //TSP_TA_SOLUTION_H