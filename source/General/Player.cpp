//
// Created by 정윤제 on 1/7/24.
//

#include "../../include/General/Player.hpp"

void Player::deploy_fleet(std::shared_ptr<TerritorialSea> sea, std::vector<std::shared_ptr<Warship>> warships) {
    int y, x;
    char direction;
    for (const auto& warship: warships) {
        std::cin >> y >> x >> direction;
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(y, x);
        // TODO: 방향 돌리기
        sea->put(warship, grid);
    }
}
