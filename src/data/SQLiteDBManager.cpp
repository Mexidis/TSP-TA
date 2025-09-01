//
// Created by pac61 on 31/08/2025.
//

#include "SQLiteDBManager.h"

#include <stdexcept>

SQLiteDBManager::SQLiteDBManager(const std::string& file_path)
{
        if (sqlite3_open(file_path.c_str(), &db_handler) != SQLITE_OK)
        {
                throw std::runtime_error("Can't open database: "+ file_path);
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

std::vector<Path> SQLiteDBManager::loadConnections()
{
}
