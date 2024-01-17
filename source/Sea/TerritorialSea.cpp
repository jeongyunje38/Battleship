//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Sea/TerritorialSea.hpp"

TerritorialSea::TerritorialSea(int _size) {
    size = _size;
    territory = std::vector<std::shared_ptr<Area>>(size * size);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            territory[map_integer(y, x)] = std::make_shared<Area>(Grid(y, x), false, false);
}

std::vector<std::shared_ptr<Area>> TerritorialSea::get_territory() {
    return territory;
}

void TerritorialSea::occupy(const std::shared_ptr<Grid>& grid) {
    territory[map_integer(grid->Y(), grid->X())]->set_has_warship(true);
}

bool TerritorialSea::is_occupied(const std::shared_ptr<Grid>& grid) {
    return territory[map_integer(grid->Y(), grid->X())]->get_has_warship();
}

int TerritorialSea::map_integer(int y, int x) const {
    return y * size + x;
}

bool TerritorialSea::is_all_revealed() {
    return std::all_of(territory.begin(), territory.end(), [&](const std::shared_ptr<Area>& area) {
        std::shared_ptr<Grid> grid = std::make_shared<Grid>(area->get_position());
        return is_occupied(grid) & area->get_is_revealed();
    });
}

void TerritorialSea::put(std::shared_ptr<Warship> warship, std::shared_ptr<Grid> grid) {
    auto shape = warship->get_shape();
    for (auto d_grid: shape) {
        int Y = grid->Y() + d_grid->Y();
        int X = grid->X() + d_grid->X();
        std::shared_ptr<Grid> target = std::make_shared<Grid>(Y, X);
        occupy(target);
    }
}

bool TerritorialSea::is_putable(const std::shared_ptr<Warship>& warship, std::shared_ptr<Grid> grid) {
    auto shape = warship->get_shape();
    return std::all_of(shape.begin(), shape.end(), [&](std::shared_ptr<Grid> d_grid){
        int Y = grid->Y() + d_grid->Y();
        int X = grid->X() + d_grid->X();
        std::shared_ptr<Grid> target = std::make_shared<Grid>(Y, X);
        return (0 <= Y & Y < size & 0 <= X & X < size & !is_occupied(target));
    });
}
