//
// Created by 정윤제 on 1/12/24.
//

#ifndef BATTLESHIP_AREA_HPP
#define BATTLESHIP_AREA_HPP

#include "Grid.hpp"

class Area {
public:
    Area(Grid _position, bool _has_warship, bool _is_revealed);
    Grid get_position();
    bool get_has_warship() const;
    void set_has_warship(bool _has_warship);
    bool get_is_revealed() const;
private:
    Grid position;
    bool has_warship;
    bool is_revealed;
};


#endif //BATTLESHIP_AREA_HPP
