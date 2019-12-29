//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include"position.hpp"

#define VIDE 0
#define DEBRIS 1
#define JOUEUR_NORMAL 8
#define JOUEUR_EXPERT 9
#define ROBOT_1GEN 3
#define ROBOT_2GEN 4

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
