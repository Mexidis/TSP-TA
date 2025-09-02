#include <sqlite3.h>
#include <gtest/gtest.h>

#include "../src/data/SQLiteDBManager.h"
#include "../src/models/Graph.h"

TEST(GraphTest, VerifyAllDistances) {
        const std::string &database_path = "../../data/data_tsp.db";

        SQLiteDBManager db(database_path);
        auto cities = db.loadCities();
        Graph graph(cities);

        sqlite3 *rawdb;
        ASSERT_EQ(SQLITE_OK, sqlite3_open(database_path.c_str(), &rawdb));

        const char *sql = "SELECT id_city_1, id_city_2, distance FROM connections;";
        sqlite3_stmt *stmt;

        ASSERT_EQ(SQLITE_OK, sqlite3_prepare_v2(rawdb, sql, -1, &stmt, nullptr));

        //compare distances between cities from connections in db
        while (sqlite3_step(stmt) == SQLITE_ROW) {
                //obtains row from db
                int id_origin = sqlite3_column_int(stmt, 0);
                int id_destiny = sqlite3_column_int(stmt, 1);
                double distance = sqlite3_column_double(stmt, 2);

                //Locates city register from id{origin,destiny} in cities vector
                City origin = cities[id_origin];
                City destination = cities[id_destiny];

                //calculates distance between cities / adds distance
                double city_distance = origin.calculateDistance(destination);
                graph.add_edge(origin.getId(), destination.getId(), city_distance);

                //compares weights of adj matrix with db
                EXPECT_DOUBLE_EQ(graph.weigth(id_origin, id_destiny), distance);
        }

        sqlite3_finalize(stmt);
        sqlite3_close(rawdb);
}
