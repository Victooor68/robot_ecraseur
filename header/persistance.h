//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_PERSISTANCE_H
#define ROBOT_ECRASEUR_PERSISTANCE_H


#include <iosfwd>
#include "doctest.h"
#include "terrain.h"

class persistance {
public:
    void static sauve(std::ofstream &f,terrain t);

    terrain restore(std::ifstream &is);
};


#endif //ROBOT_ECRASEUR_PERSISTANCE_H
