//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_H
#define ROBOT_ECRASEUR_ROBOT_H

#include "entiteMouvante.h"
#include "joueur.h"

class robot : public entiteMouvante{
public:

    robot(int x,int y);
    virtual position meilleurDeplacement(joueur* j) = 0;
private:

};


#endif //ROBOT_ECRASEUR_ROBOT_H
