//
// Created by pac61 on 31/08/2025.
//

#include "SQLiteDBManager.h"

#include <stdexcept>

#include "../models/Graph.h"

SQLiteDBManager::SQLiteDBManager(const std::string& file_path)
{
        if (sqlite3_open(file_path.c_str(), &db_handler) != SQLITE_OK)
        {
                throw std::runtime_error("Can't open data: "+ file_path);
        }
}

SQLiteDBManager::~SQLiteDBManager()
{
        if (db_handler) sqlite3_close(db_handler);
}

std::vector<City> SQLiteDBManager::loadCities()
{
        std::vector<City> cities;
        const char* sql = "SELECT id, name, latitude, longitude FROM cities;";
        sqlite3_stmt* stmt;

        //this routine is a constructor for the prepared statement object.
        if (sqlite3_prepare_v2(db_handler, sql, -1, &stmt, nullptr) != SQLITE_OK) {
                throw std::runtime_error(sqlite3_errmsg(db_handler));
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) { //The SQLITE_ROW indicates that another row of output is available.
                int id = sqlite3_column_int(stmt, 0);
                std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                double latitude = sqlite3_column_double(stmt, 2);
                double longitude = sqlite3_column_double(stmt, 3);

                //Constructor only for the 4 main atributes
                cities.emplace_back(id, name, latitude, longitude);
        }

        sqlite3_finalize(stmt);
        return cities;
}

void SQLiteDBManager::loadConnectionsFromDB(Graph& graph)
{
        const char* sql = "SELECT id_city_1, id_city_2, distance FROM connections;";
        sqlite3_stmt* stmt;

        //this routine is a constructor for the prepared statement object.
        if (sqlite3_prepare_v2(db_handler, sql, -1, &stmt, nullptr) != SQLITE_OK) {
                throw std::runtime_error(sqlite3_errmsg(db_handler));
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) { //The SQLITE_ROW indicates that another row of output is available.
                int id_city_1 = sqlite3_column_int(stmt, 0);
                int id_city_2 = sqlite3_column_int(stmt, 1);
                double distance = sqlite3_column_double(stmt, 2);

                // load the graph
                graph.add_edge(id_city_1 - 1, id_city_2 - 1, distance);
        }

        sqlite3_finalize(stmt);

}
