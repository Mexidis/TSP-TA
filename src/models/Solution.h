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
        std::vector<City> route; //cities route

public:
        Solution(std::vector<City>& cities);

        double length( CompleteGraph& GS);   // sums weights in GS
        bool isFeasible( Graph& G);          // do all the edges exist?
        std::vector<City>& getRoute();
        void setRoute(std::vector<City>& newRoute);
};


#endif //TSP_TA_SOLUTION_H