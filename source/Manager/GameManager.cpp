//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Manager/GameManager.hpp"

GameManager::GameManager(const std::string& data_path) {
    DataLoader data_loader;
    data = data_loader.read_data(data_path);
}

GameManager::~GameManager() {
    std::for_each(warships.begin(), warships.end(), [&](std::vector<Warship*> v){
        std::for_each(v.begin(), v.end(), [&](Warship* warship){
            delete warship;
        });
    });
    std::for_each(seas.begin(), seas.end(), [&](TerritorialSea* sea){
        delete sea;
    });
    std::for_each(generals.begin(), generals.end(), [&](General* general){
        delete general;
    });
}

void GameManager::init() {
    setup_var();
    deploy();
}

void GameManager::step() {
    ++turn;
}

void GameManager::run() {
    init();
    while (!is_game_over())
        step();
    print_result();
}

void GameManager::print_result() {

}

bool GameManager::is_game_over() {
    return std::any_of(seas.begin(), seas.end(), [&](TerritorialSea* sea){
        return sea->is_all_revealed();
    });
}

void GameManager::setup_var() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(false, true);
    is_player_first_attacker = distribution(gen);
    turn = 0;
    warships = {
            {
                    new Carrier(),
                    new Battleship(),
                    new Cruiser(),
                    new Submarine(),
                    new Destroyer()
            },
            {
                    new Carrier(),
                    new Battleship(),
                    new Cruiser(),
                    new Submarine(),
                    new Destroyer()
            }
    };
    seas = {
            new TerritorialSea(data["SEA_SIZE"]),
            new TerritorialSea(data["SEA_SIZE"])
    };
    generals = {
            new Player(),
            new Bot(),
    };
}

void GameManager::deploy() {
    int id = 0;
    std::for_each(generals.begin(), generals.end(), [&](General* general){
        general->deploy_fleet(seas[id], warships[id]);
        ++id;
    });
}
