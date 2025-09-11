//
// Created by patrick on 9/3/25.
//

#include "TSPInstance.h"

#include <algorithm>

TSPInstance::TSPInstance(std::vector<City> &subset, Graph &G)
        : S(subset), original_G(G), GS(CompleteGraph::generateFromSubGraph(subset)){
}

std::vector<Solution> TSPInstance::generatePermutations() {
        std::vector<Solution> solutions;

        if (S.empty()) return solutions;

        std::vector<City> perm = S;
        std::sort(perm.begin(), perm.end(), [](const City& a, const City& b){ return a.getId() < b.getId(); });

        do {
                solutions.emplace_back(perm);
        } while (std::next_permutation(perm.begin(), perm.end(), [](const City& a, const City& b){ return a.getId() < b.getId(); }));

        return solutions;
}

bool TSPInstance::isFeasable(Solution &sol) {
        return sol.isFeasible(GS);
}

double TSPInstance::maxDistance() {
        double maxDist = 0.0;
        for (size_t i = 0; i < S.size(); ++i) {
                for (size_t j = i+1; j < S.size(); ++j) {
                        double d = GS.weigth(S[i].getId(), S[j].getId());
                        if (d > maxDist) maxDist = d;
                }
        }
        return maxDist;
}

CompleteGraph& TSPInstance::getGS() {
        return GS;
}
