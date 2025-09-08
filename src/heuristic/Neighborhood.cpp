//
// Created by patrick on 9/3/25.
//

#include "Neighborhood.h"

#include <random>

#include "../models/Solution.h"

Solution Neighborhood::generateNeighbor(Solution& sol) {
        auto route = sol.getRoute();
        if (route.size() < 2) return sol;

        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<> dis(0, route.size()-1);
        int i = dis(gen);
        int j = dis(gen);
        while (i == j) j = dis(gen);

        std::swap(route[i], route[j]);

        return Solution(route);
}
