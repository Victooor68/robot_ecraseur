//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_2GEN_H
#define ROBOT_ECRASEUR_ROBOT_2GEN_H

#include "robot.h"

class robot_2gen : public robot{
public:

    robot_2gen(int x,int y);
    /**
     * Donne la direction du meilleur deplacement pour un robot 2e generation en fonction du joueur
     * @param j
     * @return direction
     */
    virtual int deplacement_Auto(joueur* j) override;

private:

};


#endif //ROBOT_ECRASEUR_ROBOT_2GEN_H
