//
// Created by patrick on 9/3/25.
//

#include "CostFunction.h"


double CostFunction::normalizer( std::vector<City>& S,  CompleteGraph& GS) {
        double maxDist = 0.0;
        for (int i = 0; i < S.size(); ++i) {
                for (int j = i+1; j < S.size(); ++j) {
                        double d = GS.weigth(S[i].getId(), S[j].getId());
                        maxDist = std::max(maxDist, d);
                }
        }
        return maxDist * S.size(); // worst case estimate
}

double CostFunction::evaluate( Solution& sol, CompleteGraph& GS) {
        return sol.length(GS);
}