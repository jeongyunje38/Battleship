//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Warship/Warship.hpp"

Warship::~Warship() {
    std::for_each(shape.begin(), shape.end(), [&](Grid* grid){
        delete grid;
    });
}

std::vector<Grid *> Warship::get_shape() {
    return shape;
}

void Warship::rotate() {
    std::for_each(shape.begin(), shape.end(), [&](Grid* grid){
        grid->transpose();
    });
}
