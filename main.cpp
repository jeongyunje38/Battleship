#include <string>
#include "include/Manager/GameManager.hpp"

int main() {
    std::string DATA_PATH = "../setting/settings.txt";
    GameManager game_manager(DATA_PATH);
    game_manager.run();
    return 0;
}
