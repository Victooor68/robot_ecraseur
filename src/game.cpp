//
// Created by totoo on 03/12/2019.
//

#include <fstream>
#include <persistance.h>
#include "../header/game.h"

void game::saveGame(std::string fileName) {
    std::ofstream myFile(fileName);
    persistance::sauve(myFile,d_terrain);
    myFile.close();
}

void game::restoreGame(std::string fileName) {
    std::ifstream myFile(fileName);
    d_terrain=persistance::restore(myFile);
    myFile.close();
}