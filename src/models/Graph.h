//
// Created by pac61 on 31/08/2025.
//

#ifndef TSP_TA_GRAPH_H
#define TSP_TA_GRAPH_H
#include <vector>

#include "City.h"
#include "Path.h"


class Graph
{
        std::vector<City> nodes;
        std::vector<std::vector<double>> adj_matrix;
public:
        // Constructor to initialize the graph with a vector of vertices (cities)
        Graph(const std::vector<City>& cities);

        void add_edge(int u_id, int v_id, double distance);
        void add_city(City city);
        double weigth(int u_id, int v_id);
        const std::vector<City>& getCities() const;
        int numCiudades() const;

};




#endif //TSP_TA_GRAPH_H