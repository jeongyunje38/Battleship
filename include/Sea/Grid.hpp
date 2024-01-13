//
// Created by 정윤제 on 1/12/24.
//

#ifndef BATTLESHIP_GRID_HPP
#define BATTLESHIP_GRID_HPP


class Grid {
public:
    Grid();
    Grid(int _y, int _x);
    int X() const;
    int Y() const;
    void transpose();
private:
    int y;
    int x;
};


#endif //BATTLESHIP_GRID_HPP
