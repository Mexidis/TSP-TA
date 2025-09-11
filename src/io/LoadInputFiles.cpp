//
// Created by patrick on 9/8/25.
//

#include "LoadInputFiles.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<int> LoadInputFiles::loadInputFile(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<int> ids;

        if (!file.is_open()) {
                throw std::runtime_error("The file couldn't be opened" + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string token;
                while (std::getline(ss, token, ',')) {
                        if (!token.empty()) {
                                ids.push_back(std::stoi(token));
                        }
                }
        }
        return ids;
}
