//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_1GEN_H
#define ROBOT_ECRASEUR_ROBOT_1GEN_H

#include "robot.h"

#define DROITE_DEPLACEMENT 0
#define GAUCHE_DEPLACEMENT 1
#define HAUT_DEPLACEMENT 2
#define BAS_DEPLACEMENT 3


class robot_1gen : public robot{
public:

    robot_1gen(int x,int y);
    virtual void deplacement_Auto(joueur* j) override;

private:

};


#endif //ROBOT_ECRASEUR_ROBOT_1GEN_H
