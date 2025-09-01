//
// Created by pac61 on 31/08/2025.
//

#ifndef TSP_TA_SQLITEDBMANAGER_H
#define TSP_TA_SQLITEDBMANAGER_H
#include <memory>
#include <sqlite3.h>
#include <vector>

#include "City.h"
#include "Path.h"

class SQLiteDBManager
{
        sqlite3* db_handler;
public:
        SQLiteDBManager(const std::string& file_path);
        ~SQLiteDBManager();

        std::vector<City>loadCities();
        std::vector<Path>loadConnections();

};


#endif //TSP_TA_SQLITEDBMANAGER_H