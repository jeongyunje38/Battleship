//
// Created by 정윤제 on 1/6/24.
//

#include "../../include/Manager/GameManager.hpp"

GameManager::GameManager(const std::string &data_path) {
    DataLoader data_loader;
    data = data_loader.read_data(data_path);
}

void GameManager::init() {
    setup_var();
    deploy();
    print();
}

void GameManager::step() {
    ++turn;
}

void GameManager::run() {
    init();
//    while (!is_game_over())
//        step();
//    print_result();
}

void GameManager::print_result() {

}

bool GameManager::is_game_over() {
    return std::any_of(seas.begin(), seas.end(), [&](std::shared_ptr<TerritorialSea> sea) {
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
                    std::make_shared<Carrier>(),
                    std::make_shared<Battleship>(),
                    std::make_shared<Cruiser>(),
                    std::make_shared<Submarine>(),
                    std::make_shared<Destroyer>()
            },
            {
                    std::make_shared<Carrier>(),
                    std::make_shared<Battleship>(),
                    std::make_shared<Cruiser>(),
                    std::make_shared<Submarine>(),
                    std::make_shared<Destroyer>()
            }
    };
    seas = {
            std::make_shared<TerritorialSea>(data["SEA_SIZE"]),
            std::make_shared<TerritorialSea>(data["SEA_SIZE"])
    };
    generals = {
            std::make_shared<Player>(),
            std::make_shared<Bot>()
    };
}

void GameManager::deploy() {
    generals[PLAYER]->deploy_fleet(seas[PLAYER], warships[PLAYER]);
    generals[BOT]->deploy_fleet(seas[BOT], warships[BOT]);
}

void GameManager::print() {
    for (int y = 0; y < data["SEA_SIZE"]; y++) {
        for (int x = 0; x < data["SEA_SIZE"]; x++)
            std::cout << seas[PLAYER]->is_occupied(std::make_shared<Grid>(y, x));
        std::cout << "\t\t";
        for (int x = 0; x < data["SEA_SIZE"]; x++)
            std::cout << seas[BOT]->is_occupied(std::make_shared<Grid>(y, x));
        std::cout << "\n";
    }
}
