//
// Created by pac61 on 31/08/2025.
//

#ifndef TSP_TA_SQLITEDBMANAGER_H
#define TSP_TA_SQLITEDBMANAGER_H
#include <memory>
#include <sqlite3.h>
#include <vector>

#include "../models/Graph.h"
#include "../models/City.h"
#include "../models/Path.h"

class SQLiteDBManager
{
        sqlite3* db_handler;
public:
        SQLiteDBManager(const std::string& file_path);
        ~SQLiteDBManager();

        std::vector<City>loadCities();
        void loadConnectionsFromDB(Graph& cities);

};


#endif //TSP_TA_SQLITEDBMANAGER_H