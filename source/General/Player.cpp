//
// Created by 정윤제 on 1/7/24.
//

#include "../../include/General/Player.hpp"

void Player::deploy_fleet(TerritorialSea* sea, std::vector<Warship*> warships) {
    int y, x;
    char direction;
    std::for_each(warships.begin(), warships.end(), [&](Warship* warship){
        std::cin >> y >> x >> direction;
        Grid* grid = new Grid(y, x);
        // TODO: 방향 돌리기
        sea->put(warship, grid);
        delete grid;
    });
}
