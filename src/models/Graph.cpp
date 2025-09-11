//
// Created by pac61 on 31/08/2025.
//

#include "Graph.h"

#include <limits>


Graph::Graph(const std::vector<City>& cities): nodes(cities)
{
        int n = cities.size();
        adj_matrix = std::vector<std::vector<double>>(
                        n+1, std::vector<double> (n+1, std::numeric_limits<double>::infinity()));
}

void Graph::add_edge(int u_id, int v_id, double distance)
{
        adj_matrix[u_id][v_id] = distance;
        adj_matrix[v_id][u_id] = distance;
}

void Graph::add_edge(City city1, City city2) {
        double distance = city1.calculateDistance(city2);
        adj_matrix[city1.getId()][city2.getId()] = distance;
        adj_matrix[city2.getId()][city1.getId()] = distance;
}

double Graph::weigth(int u_id, int v_id)
{
        return adj_matrix[u_id][v_id];
}

const std::vector<City>& Graph::getCities() const
{
        return nodes;
}

int Graph::numCities() const
{
        return nodes.size();
}

void Graph::add_city(City city) {
        nodes.push_back(city);
}

std::vector<City> Graph::getNodes() {
        return nodes;
}

std::vector<std::vector<double>> Graph::get_adj_matrix() {
        return adj_matrix;
}

void Graph::setNodes(std::vector<City> cities) {
        this->nodes = cities;
}

void Graph::setAdjMatrix(std::vector<std::vector<double>> adj_matrix) {
        this->adj_matrix = adj_matrix;
}
