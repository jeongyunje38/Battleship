//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Warship/Warship.hpp"

std::vector<std::shared_ptr<Grid>> Warship::get_shape() {
    return shape;
}

void Warship::rotate() {
    for (const auto& grid: shape)
        grid->transpose();
}
