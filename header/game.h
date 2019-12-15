//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_GAME_H
#define ROBOT_ECRASEUR_GAME_H


#include "terrain.h"

class game {
public:
    void saveGame(std::string fileName);
    void restoreGame(std::string fileName);
private:
    terrain d_terrain;
};


#endif //ROBOT_ECRASEUR_GAME_H
