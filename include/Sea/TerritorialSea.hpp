//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_TERRITORIALSEA_HPP
#define BATTLESHIP_TERRITORIALSEA_HPP

#include <vector>
#include <algorithm>
#include "Grid.hpp"
#include "Area.hpp"
#include "../Warship/Warship.hpp"

class TerritorialSea {
public:
    explicit TerritorialSea(int _size);
    ~TerritorialSea();
    std::vector<Area*> get_territory();
    void occupy(Grid* grid);
    bool is_occupied(Grid* grid);
    bool is_all_revealed();
    void put(Warship* warship, Grid* grid);
    bool is_putable(Warship* warship, Grid* grid);
private:
    int size;
    std::vector<Area*> territory;
    [[nodiscard]] int map_integer(int y, int x) const;
};


#endif //BATTLESHIP_TERRITORIALSEA_HPP
