cmake_minimum_required(VERSION 3.27)
project(Battleship)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        Battleship main.cpp
        source/General/General.cpp
        include/General/General.hpp
        source/General/Bot.cpp
        include/General/Bot.hpp
        source/General/Player.cpp
        include/General/Player.hpp
        source/Manager/GameManager.cpp
        include/Manager/GameManager.hpp
        source/Sea/Area.cpp
        include/Sea/Area.hpp
        source/Sea/Grid.cpp
        include/Sea/Grid.hpp
        source/Sea/TerritorialSea.cpp
        include/Sea/TerritorialSea.hpp
        source/Util/DataLoader.cpp
        include/Util/DataLoader.hpp
        source/Warship/Battleship.cpp
        include/Warship/Battleship.hpp
        source/Warship/Carrier.cpp
        include/Warship/Carrier.hpp
        source/Warship/Cruiser.cpp
        include/Warship/Cruiser.hpp
        source/Warship/Destroyer.cpp
        include/Warship/Destroyer.hpp
        source/Warship/Submarine.cpp
        include/Warship/Submarine.hpp
        source/Warship/Warship.cpp
        include/Warship/Warship.hpp

)
