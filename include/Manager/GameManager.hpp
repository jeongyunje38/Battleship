//
// Created by 정윤제 on 1/6/24.
//

#ifndef BATTLESHIP_GAMEMANAGER_HPP
#define BATTLESHIP_GAMEMANAGER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <memory>
#include "../Util/DataLoader.hpp"
#include "../Warship/Warship.hpp"
#include "../Warship/Carrier.hpp"
#include "../Warship/Battleship.hpp"
#include "../Warship/Cruiser.hpp"
#include "../Warship/Submarine.hpp"
#include "../Warship/Destroyer.hpp"
#include "../Sea/TerritorialSea.hpp"
#include "../General/General.hpp"
#include "../General/Player.hpp"
#include "../General/Bot.hpp"

class GameManager {
public:
    explicit GameManager(const std::string &data_path);

    void init();

    void step();

    void run();

    void print_result();

    bool is_game_over();

    void setup_var();

    void deploy();

    void print();

private:
    enum who {
        PLAYER, BOT
    };
    bool is_player_first_attacker;
    int turn;
    std::map<std::string, int> data;
    std::vector<std::vector<std::shared_ptr<Warship>>> warships;
    std::vector<std::shared_ptr<TerritorialSea>> seas;
    std::vector<std::shared_ptr<General>> generals;
};


#endif //BATTLESHIP_GAMEMANAGER_HPP
