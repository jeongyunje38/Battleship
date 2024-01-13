//
// Created by 정윤제 on 1/7/24.
//

#ifndef BATTLESHIP_BOT_HPP
#define BATTLESHIP_BOT_HPP

#include <random>
#include <cmath>
#include "General.hpp"

class Bot : public General {
public:
    void deploy_fleet(TerritorialSea *sea, std::vector<Warship *> warships) override;
};


#endif //BATTLESHIP_BOT_HPP
