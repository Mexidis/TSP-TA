//
// Created by patrick on 9/2/25.
//
#include "CompleteGraph.h"
#include <limits>
#include "Graph.h"


CompleteGraph::CompleteGraph(std::vector<City> &subset): Graph(subset){
}

CompleteGraph CompleteGraph::generateFromSubGraph(Graph &original, std::vector<City> &subset) {
        CompleteGraph gs(subset);

        for (int i = 0; i < (int)subset.size(); ++i) {
                for (int j = i+1; j < (int)subset.size(); ++j) {
                        double distance = subset[i].calculateDistance(subset[j]); //using coordinates
                        gs.add_edge(subset[i].getId(), subset[j].getId(), distance);
                }
        }
        return gs;
}

void CompleteGraph::applyWeigthAugmentedFuntion() {
        for (auto& row : get_adj_matrix()) {
                for (auto& w : row) {
                        if (w != std::numeric_limits<double>::infinity()) {
                                w *= 1.05; //5% penalty
                        }
                }
        }
}
