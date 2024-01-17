//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_TERRITORIALSEA_HPP
#define BATTLESHIP_TERRITORIALSEA_HPP

#include <vector>
#include <algorithm>
#include <memory>
#include "Grid.hpp"
#include "Area.hpp"
#include "../Warship/Warship.hpp"

class TerritorialSea {
public:
    explicit TerritorialSea(int _size);
    std::vector<std::shared_ptr<Area>> get_territory();
    void occupy(const std::shared_ptr<Grid>& grid);
    bool is_occupied(const std::shared_ptr<Grid>& grid);
    bool is_all_revealed();
    void put(std::shared_ptr<Warship> warship, std::shared_ptr<Grid> grid);
    bool is_putable(const std::shared_ptr<Warship>& warship, std::shared_ptr<Grid> grid);
private:
    int size;
    std::vector<std::shared_ptr<Area>> territory;
    [[nodiscard]] int map_integer(int y, int x) const;
};


#endif //BATTLESHIP_TERRITORIALSEA_HPP
