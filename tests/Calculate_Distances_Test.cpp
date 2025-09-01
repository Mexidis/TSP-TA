//TODO configure correctly this TEST
#include <sqlite3.h>
#include <gtest/gtest.h>

#include "SQLiteDBManager.h"
#include "models/Graph.h"

TEST(GraphTest, VerifyAllDistances) {
        SQLiteDBManager db("data/data_tsp.db");
        auto cities = db.loadCities();

        const std::vector<City> conn(cities);              //create a graph using the cities
        db.loadConnections(conn);        //connect cities

        sqlite3* rawdb;
        ASSERT_EQ(SQLITE_OK, sqlite3_open("data/data_tsp.db", &rawdb));

        const char* sql = "SELECT id_city_1, id_city_2, distance FROM connections;";
        sqlite3_stmt* stmt;

        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(rawdb, sql, -1, &stmt, nullptr));

        while (sqlite3_step(stmt) == SQLITE_ROW) {
                int id_origin = sqlite3_column_int(stmt, 0);
                int id_destiny = sqlite3_column_int(stmt, 1);
                double distance = sqlite3_column_double(stmt, 2);

                EXPECT_DOUBLE_EQ(graph.weigth(id_origin, id_destiny), distance);
        }

        sqlite3_finalize(stmt);
        sqlite3_close(rawdb);
}
