//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_TSPINSTANCE_H
#define TSP_TA_TSPINSTANCE_H
#include "CompleteGraph.h"


class TSPInstance {
private:
        std::vector<City> S;      // instance subset cities
        const Graph& original_G;  // main graph with all cities
        CompleteGraph GS;         // complete graph made by S
        double normalizer;        // N(S)

public:
        TSPInstance( std::vector<City>& subset, Graph& G);

        double getNormalizer() { return normalizer; }
        CompleteGraph& getGS() { return GS; }

        double computeNormalizer();   // calculates N(S)
};


#endif //TSP_TA_TSPINSTANCE_H