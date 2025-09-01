#include <iostream>
#include "City.h"
#include "data/SQLiteDBManager.h"

int main()
{
        std::string databasePath = "data/data_tsp.db";
        try
        {
                //connect to database
                SQLiteDBManager db(databasePath);

                //load data
                auto cities = db.loadCities();
                auto conn = db.loadConnections(cities);

        } catch   (const std::exception& e) {
                std::runtime_error(sqliteError());
        }


        return 0;
}
