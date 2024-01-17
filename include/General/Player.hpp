//
// Created by 정윤제 on 1/7/24.
//

#ifndef BATTLESHIP_PLAYER_HPP
#define BATTLESHIP_PLAYER_HPP

#include <iostream>
#include "General.hpp"

class Player : public General {
public:
    void deploy_fleet(std::shared_ptr<TerritorialSea> sea, std::vector<std::shared_ptr<Warship>> warships) override;
};


#endif //BATTLESHIP_PLAYER_HPP
