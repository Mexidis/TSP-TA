//
// Created by pac61 on 31/08/2025.
//

#include "Graph.h"

#include <limits>


Graph::Graph(const std::vector<City>& cities): nodes(cities)
{
        int n = cities.size();
        adj_matrix = std::vector<std::vector<double>>(
                        n, std::vector<double> (n, std::numeric_limits<double>::infinity()));
}

void Graph::add_edge(int u_id, int v_id, double distance)
{
        adj_matrix[u_id][v_id] = distance;
        adj_matrix[v_id][u_id] = distance;
}

double Graph::weigth(int u_id, int v_id)
{
        return adj_matrix[u_id][v_id];
}

const std::vector<City>& Graph::getCities() const
{
        return nodes;
}

int Graph::numCiudades() const
{
        return nodes.size();
}

