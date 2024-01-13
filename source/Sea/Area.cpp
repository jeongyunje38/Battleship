//
// Created by 정윤제 on 1/12/24.
//

#include "../../include/Sea/Area.hpp"

Area::Area(Grid _position, bool _has_warship, bool _is_revealed) {
    position = _position;
    has_warship = _has_warship;
    is_revealed = _is_revealed;
}

Grid Area::get_position() {
    return position;
}

bool Area::get_has_warship() const {
    return has_warship;
}

void Area::set_has_warship(bool _has_warship) {
    has_warship = _has_warship;
}

bool Area::get_is_revealed() const {
    return is_revealed;
}
