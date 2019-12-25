//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_1GEN_H
#define ROBOT_ECRASEUR_ROBOT_1GEN_H


#include "robot.h"

class robot_1gen : public robot{
public:

    robot_1gen(int x,int y);
    virtual void deplacementAuto() override;

private:

};


#endif //ROBOT_ECRASEUR_ROBOT_1GEN_H
