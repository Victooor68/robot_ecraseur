//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ROBOT_H
#define ROBOT_ECRASEUR_ROBOT_H

#include "entiteMouvante.h"
#include "joueur.h"

#define BAS_DEPLACEMENT 0
#define HAUT_DEPLACEMENT 1
#define GAUCHE_DEPLACEMENT 2
#define DROITE_DEPLACEMENT 3
#define HAUT_DROITE_DEPLACEMENT 4
#define BAS_DROITE_DEPLACEMENT 5
#define HAUT_GAUCHE_DEPLACEMENT 6
#define BAS_GAUCHE_DEPLACEMENT 7


class robot : public entiteMouvante{
public:

    robot(int x,int y);
    /**
     * Donne la direction du meilleur deplacement pour un robot en fonction du joueur
     * @param j
     * @return direction
     */
    virtual int deplacement_Auto(joueur* j) = 0;
private:

};


#endif //ROBOT_ECRASEUR_ROBOT_H
