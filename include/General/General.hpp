//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_GENERAL_HPP
#define BATTLESHIP_GENERAL_HPP

#include <vector>
#include "../Sea/TerritorialSea.hpp"
#include "../Warship/Warship.hpp"

class General {
public:
    virtual void deploy_fleet(TerritorialSea *sea, std::vector<Warship *> warships);
};


#endif //BATTLESHIP_GENERAL_HPP
