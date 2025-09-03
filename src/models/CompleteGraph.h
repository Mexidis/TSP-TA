//
// Created by patrick on 9/2/25.
//

#ifndef TSP_TA_COMPLETEGRAPH_H
#define TSP_TA_COMPLETEGRAPH_H
#include "Graph.h"


class CompleteGraph:public Graph {
public:
        CompleteGraph(const std::vector<City>& subset, const Graph& G);

        double maxd(const std::vector<City>& S) const;   // calculates maxDistance(S)
        double weight(int u_id, int v_id) const override; // redefines weight with cost Function

};


#endif //TSP_TA_COMPLETEGRAPH_H