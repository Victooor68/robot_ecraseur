//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include"position.hpp"
#include"terrain.h"
#include<iostream>

class entite {
public:




private:
    position d_pos;
    std::string d_name;
    terrain& d_ter;
};


#endif //ROBOT_ECRASEUR_ENTITE_H
