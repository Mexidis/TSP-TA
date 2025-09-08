//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_COSTFUNCTION_H
#define TSP_TA_COSTFUNCTION_H
#include "../models/Solution.h"
#include "../models/TSPInstance.h"

class CostFunction {
public:
        static double normalizer(std::vector<City>& S, CompleteGraph& GS);
        static double evaluate(Solution& sol, CompleteGraph& GS);
};


#endif //TSP_TA_COSTFUNCTION_H