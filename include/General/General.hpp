//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_GENERAL_HPP
#define BATTLESHIP_GENERAL_HPP

#include <vector>
#include <memory>
#include "../Sea/TerritorialSea.hpp"
#include "../Warship/Warship.hpp"

class General {
public:
    virtual void deploy_fleet(std::shared_ptr<TerritorialSea> sea, std::vector<std::shared_ptr<Warship>> warships) = 0;
};


#endif //BATTLESHIP_GENERAL_HPP
