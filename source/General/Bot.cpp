//
// Created by 정윤제 on 1/7/24.
//

#include "../../include/General/Bot.hpp"

void Bot::deploy_fleet(std::shared_ptr<TerritorialSea> sea, std::vector<std::shared_ptr<Warship>> warships) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int square_num = (int)sea->get_territory().size();
    int size = (int)std::sqrt(square_num);
    for (const auto& warship: warships) {
        std::uniform_int_distribution<int> rand_for_rot(0, 100);
        int rotate_prob = rand_for_rot(gen);
        if (rotate_prob > 50) warship->rotate();
        std::vector<std::shared_ptr<Grid>> shape = warship->get_shape();
        int max_dy = 0, max_dx = 0;
        for (const auto& s: shape)
        {
            int dy = s->Y(), dx = s->X();
            if (max_dy < dy) max_dy = dy;
            if (max_dx < dx) max_dx = dx;
        }
        std::uniform_int_distribution<int> rand_for_y(0, size - 1 - max_dy);
        std::uniform_int_distribution<int> rand_for_x(0, size - 1 - max_dx);
        int y, x;
        std::shared_ptr<Grid> grid;
        do {
            y = rand_for_y(gen), x = rand_for_x(gen);
            grid = std::make_shared<Grid>(y, x);
        } while (sea->is_putable(warship, grid));
        sea->put(warship, grid);
    };
}
