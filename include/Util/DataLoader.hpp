//
// Created by 정윤제 on 1/12/24.
//

#ifndef BATTLESHIP_DATALOADER_HPP
#define BATTLESHIP_DATALOADER_HPP

#include <fstream>
#include <map>
#include <string>

class DataLoader {
public:
    std::map<std::string, int> read_data(const std::string& path);
private:
    std::map<std::string, int> data;
};


#endif //BATTLESHIP_DATALOADER_HPP
