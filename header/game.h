//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_GAME_H
#define ROBOT_ECRASEUR_GAME_H


#include "terrain.h"
#include "entite.h"

class game {
public:
    game();
    void init();
    void saveGame(std::string fileName);
    void restoreGame(std::string fileName);
private:
    terrain d_terrain;
    std::vector<entite> d_entite;

    std::vector<entite> restoreEntiteDeTerrain(terrain terrain);
};


#endif //ROBOT_ECRASEUR_GAME_H
