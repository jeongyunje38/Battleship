//
// Created by 정윤제 on 1/12/24.
//

#include "../../include/Sea/Grid.hpp"

Grid::Grid() {
    y = 0;
    x = 0;
}

Grid::Grid(int _y, int _x) {
    y = _y;
    x = _x;
}

int Grid::X() const {
    return x;
}

int Grid::Y() const {
    return y;
}

void Grid::transpose() {
    int temp = y;
    y = x;
    x = temp;
}
