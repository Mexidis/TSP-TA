//
// Created by patrick on 9/3/25.
//

#include "ThresholdAccepting.h"

#include <cmath>
#include <limits>

#include "CostFunction.h"
#include "Neighborhood.h"


ThresholdAccepting::ThresholdAccepting(double initial_T, double phi, double epsilon, int Len):
        T(initial_T), phi(phi), epsilon(epsilon), L(Len)
{
}

std::pair<double, Solution> ThresholdAccepting::calculateBatch(double T, Solution &s, CompleteGraph &GS) {
        int c = 0;
        double r = 0.0;
        Solution currentSol = s;

        int attempts = 0;
        const int MAX_ATTEMPTS = L * 10;

        while (c < L && attempts < MAX_ATTEMPTS) {
                Solution neighbor = Neighborhood::generateNeighbor(currentSol);
                double current_f = CostFunction::evaluate(currentSol, GS);
                double neighbor_f = CostFunction::evaluate(neighbor, GS);

                 if (neighbor_f <= current_f + T) { // accepting condition
                        currentSol = neighbor;
                        c++;
                        r += neighbor_f;
                }
                attempts++;
        }
        double average = (c > 0) ? r / c : std::numeric_limits<double>::infinity();
        return {average, currentSol};
}

Solution ThresholdAccepting::execute(Solution &initial_s, CompleteGraph &GS) {
        Solution s = initial_s;
        bestSolution = s;

        double p = 0;
        while (T > epsilon) {
                double q = std::numeric_limits<double>::infinity();
                while (p <= q) { //thermical balance
                        q = p;
                        auto batch = calculateBatch(T, s, GS);
                        p = batch.first;
                        s = batch.second;

                        if (CostFunction::evaluate(s, GS) < CostFunction:: evaluate(bestSolution, GS)) {
                                bestSolution = s;
                        }
                }
                T *= phi; //cooling T
        }
        return bestSolution;

}

double ThresholdAccepting::acceptedPercentage(Solution &s, double T, CompleteGraph &GS, int N) {
        int c = 0;
        Solution currentSol = s;
        for (int i = 0; i < N; i++) {
                Solution neighbor = Neighborhood::generateNeighbor(currentSol);
                double current_f = CostFunction::evaluate(currentSol, GS);
                double neighbor_f = CostFunction::evaluate(neighbor, GS);

                if (neighbor_f <= current_f + T) {
                        c++;
                        currentSol = neighbor;
                }
        }
        return static_cast<double>(c) / N;
}

double ThresholdAccepting::binarySearch(Solution &s, double T1, double T2, double P, CompleteGraph &GS, int N,
        double epsilon) {
        double Tm = (T1 + T2) / 2.0;
        if (T2 - T1 < epsilon) return Tm;

        double p = acceptedPercentage(s, Tm, GS, N);
        if (std::fabs(P - p) < epsilon) return Tm;

        if (p > P) {
                return binarySearch(s, T1, Tm, P, GS, N, epsilon);
        } else {
                return binarySearch(s, Tm, T2, P, GS, N, epsilon);
        }
}

double ThresholdAccepting::initialTemperature(Solution &s, CompleteGraph &GS, double P, int N, double epsilon) {
        double T = 1.0;
        double p = acceptedPercentage(s, T, GS, N);

        if (std::fabs(P - p) <= epsilon) return T;

        if (p < P) {
                while (p < P) {
                        T *= 2;
                        p = acceptedPercentage(s, T, GS, N);
                }
                return binarySearch(s, T/2, T, P, GS, N, epsilon);
        } else {
                while (p > P) {
                        T /= 2;
                        p = acceptedPercentage(s, T, GS, N);
                }
                return binarySearch(s, T, 2*T, P, GS, N ,epsilon);
        }
}
