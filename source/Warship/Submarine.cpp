//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Warship/Submarine.hpp"

Submarine::Submarine() {
    shape = {
            std::make_shared<Grid>(0, 0),
            std::make_shared<Grid>(1, 0),
            std::make_shared<Grid>(2, 0)
    };
}
