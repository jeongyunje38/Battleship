//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Warship/Carrier.hpp"

Carrier::Carrier() {
    shape = {
            new Grid(0, 0),
            new Grid(1, 0),
            new Grid(2, 0),
            new Grid(3, 0),
            new Grid(4, 0)
    };
}
