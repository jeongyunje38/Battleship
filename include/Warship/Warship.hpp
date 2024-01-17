//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_WARSHIP_HPP
#define BATTLESHIP_WARSHIP_HPP

#include <vector>
#include <algorithm>
#include <memory>
#include "../Sea/Grid.hpp"

class Warship {
public:
    std::vector<std::shared_ptr<Grid>> get_shape();
    void rotate();
protected:
    std::vector<std::shared_ptr<Grid>> shape;
};


#endif //BATTLESHIP_WARSHIP_HPP
