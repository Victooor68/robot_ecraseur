//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include"position.hpp"
#include"terrain.h"

class entite {
public:
    //constructor with 2 int
    entite(int x, int y);
    //constructor with position
    entite(position position);
    //accessor type
    int Type();
    //accessor position
    position Position();
private:
    position d_pos;
    int d_type;
};


#endif //ROBOT_ECRASEUR_ENTITE_H
