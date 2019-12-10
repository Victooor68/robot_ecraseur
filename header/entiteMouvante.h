//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_MOUVANTE_H
#define ROBOT_ECRASEUR_MOUVANTE_H

#include "entite.h"
#include"position.hpp"

class entiteMouvante : public entite{
public:
    entiteMouvante(int x, int y);

    entiteMouvante(class position position);


    /**
     * Permet à l'entité de deplacer sa position de 1 à Droite
     */
    void seDeplaceADroite();

    /**
     * Permet à l'entité de deplacer sa position de 1 à Gauche
     */
    void seDeplaceAGauche();

    /**
     * Permet à l'entité de deplacer sa position de 1 en Bas
     */
    void seDeplaceEnBas();

    /**
     * Permet à l'entité de deplacer sa position de 1 en Haut
     */
    void seDeplaceEnHaut();



private:

};


#endif //ROBOT_ECRASEUR_MOUVANTE_H
