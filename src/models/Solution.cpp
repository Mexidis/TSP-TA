//
// Created by patrick on 9/3/25.
//

#include "Solution.h"

#include <limits>

Solution::Solution(){}

Solution::Solution(std::vector<City> &route) : route(route){
}

double Solution::length(CompleteGraph &GS){
        if (route.size() < 2) return 0.0;

        double total = 0.0;
        for (int i = 0; i < (int)route.size() - 1; ++i) {
                total += GS.weigth(route[i].getId(), route[i+1].getId());
        }

        total += GS.weigth(route.back().getId(), route.front().getId());

        return total;
}

bool Solution::isFeasible(Graph &g) {
        //a solution is feasible when it visits each city with no repetition
        //and there are no infinite weights
        if (route.empty()) return false;

        std::vector<bool> visited(g.numCities(), false);
        for (const auto& c : route) {
                if (c.getId() < 0 || c.getId() >= g.numCities()) return false;
                if (visited[c.getId()]==true) return false; //we need no repetition
                visited[c.getId()] = true;//otherwise
        }
        // check that the cycle can be closed
        double lastEdge = g.weigth(route.back().getId(), route.front().getId());
        return lastEdge != std::numeric_limits<double>::infinity();//
}

std::vector<City> & Solution::getRoute() {
        return route;
}

void Solution::setRoute(std::vector<City>& newRoute) {
        route = newRoute;
}
