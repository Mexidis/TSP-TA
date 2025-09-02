#include <iostream>
#include "src/models/City.h"
#include "src/data/SQLiteDBManager.h"

int main()
{
        const std::string& databasePath = "../data/data_tsp.db";
        try
        {
                //connect to data
                SQLiteDBManager db(databasePath);

                //load data
                auto cities = db.loadCities();
                Graph graph(cities);
                db.loadConnectionsFromDB(graph);

        } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
        }


        return 0;
}
