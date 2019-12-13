//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_GAME_H
#define ROBOT_ECRASEUR_GAME_H

#include "../header/terrain.h"

class game {
public:
    game(int width, int hauteur);
private:
    int d_MAXWIDTH;
    int d_MAXHEIGHT;
    terrain& d_t;
};


#endif //ROBOT_ECRASEUR_GAME_H
