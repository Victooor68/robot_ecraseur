//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include <string>
#include"position.hpp"

#define VIDE 0
#define DEBRIS 1
#define JOUEUR_NORMAL 2
#define JOUEUR_EXPERT 3
#define ROBOT_1GEN 4
#define ROBOT_2GEN 5

class entite {
public:
    entite(int x, int y);
    entite(const position& position);
    ~entite();
    position getPosition() const;
    int getType() const;

protected:
    position d_pos;
    int d_type;
};

#endif //ROBOT_ECRASEUR_ENTITE_H
