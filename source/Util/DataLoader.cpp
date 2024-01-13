//
// Created by 정윤제 on 1/12/24.
//

#include "../../include/Util/DataLoader.hpp"

std::map<std::string, int> DataLoader::read_data(const std::string& path) {
    std::ifstream file(path);
    std::string key, val;
    while (file >> key >> val) {
        int v = std::stoi(val);
        data[key] = v;
    }
    file.close();
    return data;
}
