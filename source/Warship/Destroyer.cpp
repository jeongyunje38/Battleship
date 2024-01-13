//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Warship/Destroyer.hpp"

Destroyer::Destroyer() {
    shape = {
            new Grid(0, 0),
            new Grid(1, 0)
    };
}
