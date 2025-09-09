//
// Created by patrick on 9/8/25.
//

#include "LoadInputFiles.h"

std::vector<int> loadInputFile(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<int> ids;

        std::string line;
        while (std::getline(file, line)) {
                if (line.rfind("Path:", 0) == 0) {  // línea que empieza con "Path:"
                        std::string pathStr = line.substr(5); // quitar "Path:"
                        std::stringstream ss(pathStr);
                        std::string token;
                        while (std::getline(ss, token, ',')) {
                                ids.push_back(std::stoi(token));
                        }
                }
        }
        return ids;
}