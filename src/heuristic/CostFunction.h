//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_COSTFUNCTION_H
#define TSP_TA_COSTFUNCTION_H


class CostFunction {
public:
        static double evaluate(const Solution& P, const TSPInstance& inst) {
                double numerator = P.length(inst.getGS());
                return numerator / inst.getNormalizer();
        }
};


#endif //TSP_TA_COSTFUNCTION_H