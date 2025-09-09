//
// Created by patrick on 9/3/25.
//

#ifndef TSP_TA_THRESHOLDACCEPTING_H
#define TSP_TA_THRESHOLDACCEPTING_H
#include <utility>

#include "../models/Solution.h"
#include "../models/CompleteGraph.h"

class ThresholdAccepting {
private:
        double T;      // temperature
        double phi;    // cooling factor
        double epsilon;
        int L;         // batch size
        Solution bestSolution;

public:
        ThresholdAccepting(double initial_T, double phi, double epsilon, int Len);

        std::pair<double, Solution> calculateBatch(double T, Solution& s, CompleteGraph& GS);
        Solution execute(Solution& s_inicial, CompleteGraph& GS);

        double acceptedPercentage(Solution& s, double T, CompleteGraph& GS, int N);

        double binarySearch(Solution& s, double T1, double T2, double P,
                            CompleteGraph& GS, int N, double epsilon);

        double initialTemperature(Solution& s, CompleteGraph& GS, double P, int N);
};


#endif //TSP_TA_THRESHOLDACCEPTING_H