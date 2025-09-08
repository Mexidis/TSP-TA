//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_TSPINSTANCE_H
#define TSP_TA_TSPINSTANCE_H
#include "CompleteGraph.h"
#include "Solution.h"


class TSPInstance {
private:
        std::vector<City> S;      // instance subset cities
        const Graph& original_G;  // main graph with all cities
        CompleteGraph GS;         // complete graph made by S

public:
        TSPInstance(std::vector<City>& subset, Graph& G);

        std::vector<Solution> generatePermutations();
        bool isFeasable(Solution& sol);
        double maxDistance();  // max distance in S

        CompleteGraph& getGS();

};


#endif //TSP_TA_TSPINSTANCE_H