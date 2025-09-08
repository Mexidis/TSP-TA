//
// Created by patrick on 9/2/25.
//

#ifndef TSP_TA_COMPLETEGRAPH_H
#define TSP_TA_COMPLETEGRAPH_H
#include "Graph.h"


class CompleteGraph:public Graph {
public:
        CompleteGraph(const std::vector<City>& subset);

        // build the complete graph from subset S
        static CompleteGraph generateFromSubGraph(const Graph& original, const std::vector<City>& subset);

        // apply weigth augmented function
        void applyWeigthAugmentedFuntion();

};


#endif //TSP_TA_COMPLETEGRAPH_H