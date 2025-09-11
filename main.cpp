#include <algorithm>
#include <iostream>
#include "src/models/City.h"
#include "src/heuristic/CostFunction.h"
#include "src/heuristic/ThresholdAccepting.h"
#include "src/data/SQLiteDBManager.h"
#include "src/io/LoadInputFiles.h"
#include <vector>

#include "src/models/TSPInstance.h"

int main() {
        const std::string &databasePath = "../data/data_tsp.db";
        //connect to database
        SQLiteDBManager db(databasePath);

        //load data
        auto all_cities = db.loadCities();
        Graph graph(all_cities);
        db.loadConnectionsFromDB(graph);

        // read tsp-instance
        const std::string tsp_40 = "/home/patrick/develop/TSP-TA/inputs/input-40.tsp";
        auto id_cities = LoadInputFiles::loadInputFile(tsp_40);
        // for (int id: id_cities) {
        //         std::cout << id << std::endl;
        // }

        //create a subset S
        std::vector<City> cities_subset;
        for (int id: id_cities) {
                auto it = std::find_if(all_cities.begin(), all_cities.end(),
                                       [id](const City &c) { return c.getId() == id; });
                if (it != all_cities.end()) cities_subset.push_back(*it);
        }

        //create instance
        TSPInstance instance(cities_subset, graph);

        //create initial solution
        Solution initial_solution(cities_subset);

        //calculate metrics
        double max = instance.maxDistance();
        double normalizer = CostFunction::normalizer(cities_subset, instance.getGS());
        double evaluation = CostFunction::evaluate(initial_solution, instance.getGS());
        bool feasable = initial_solution.isFeasible(instance.getGS());

        std::cout << "Maximum: " << max << "\n";
        std::cout << "Normalizer: " << normalizer << "\n";
        std::cout << "Evaluation: " << evaluation << "\n";
        std::cout << "Feasible: " << (feasable ? "YES" : "NO") << "\n";

        //execute TA
        ThresholdAccepting ta(50000.0, 0.9, 0.001, 50);
        Solution best_yet = ta.execute(initial_solution, instance.getGS());
        std::cout << "Best evaluation: " << CostFunction::evaluate(best_yet, instance.getGS()) << std::endl;
        return 0;
}
