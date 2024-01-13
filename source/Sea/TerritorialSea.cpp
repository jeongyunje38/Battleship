//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Sea/TerritorialSea.hpp"

TerritorialSea::TerritorialSea(int _size) {
    size = _size;
    territory = std::vector<Area*>(size * size);
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            territory[map_integer(y, x)] = new Area(Grid(y, x), false, false);
}

TerritorialSea::~TerritorialSea() {
    std::for_each(territory.begin(), territory.end(), [&](Area* area){
        delete area;
    });
}

std::vector<Area*> TerritorialSea::get_territory() {
    return territory;
}

void TerritorialSea::occupy(Grid* grid) {
    territory[map_integer(grid->Y(), grid->X())]->set_has_warship(true);
}

bool TerritorialSea::is_occupied(Grid* grid) {
    return territory[map_integer(grid->Y(), grid->X())]->get_has_warship();
}

int TerritorialSea::map_integer(int y, int x) const {
    return y * size + x;
}

bool TerritorialSea::is_all_revealed() {
    return std::all_of(territory.begin(), territory.end(), [&](Area* area){
        Grid *grid = new Grid(area->get_position());
        bool ret = is_occupied(grid) & area->get_is_revealed();
        delete grid;
        return ret;
    });
}

void TerritorialSea::put(Warship *warship, Grid *grid) {
    std::for_each(warship->get_shape().begin(), warship->get_shape().end(), [&](Grid* d_grid){
        Grid* target = new Grid(grid->Y() + d_grid->Y(), grid->X() + d_grid->X());
        occupy(target);
        delete target;
    });
}

bool TerritorialSea::is_putable(Warship *warship, Grid *grid) {
    return std::all_of(warship->get_shape().begin(), warship->get_shape().end(), [&](Grid* d_grid){
        int Y = grid->Y() + d_grid->Y();
        int X = grid->X() + d_grid->X();
        Grid* target = new Grid(Y, X);
        bool ret = 0 <= Y & Y < size & 0 <= X & X < size & !is_occupied(target);
        delete target;
        return ret;
    });
}
