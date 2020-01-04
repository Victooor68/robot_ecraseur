//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_H
#define ROBOT_ECRASEUR_ROBOT_H

#include "entiteMouvante.h"
#include "joueur.h"

#define DROITE_DEPLACEMENT 0
#define GAUCHE_DEPLACEMENT 1
#define HAUT_DEPLACEMENT 2
#define BAS_DEPLACEMENT 3
#define BAS_GAUCHE_DEPLACEMENT 4
#define BAS_DROITE_DEPLACEMENT 5
#define HAUT_GAUCHE_DEPLACEMENT 6
#define HAUT_DROITE_DEPLACEMENT 7


class robot : public entiteMouvante{
public:

    robot(int x,int y);
    virtual int deplacement_Auto(joueur* j) = 0;
private:

};


#endif //ROBOT_ECRASEUR_ROBOT_H
