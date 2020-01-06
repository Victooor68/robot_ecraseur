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

    /**
     * Permet à l'entite de se déplacer en diagonale en haut à droite
     */
    void seDeplaceEnHautADroite();

    /**
     * Permet à l'entite de se déplacer en diagonale en bas à droite
     */
    void seDeplaceEnBasADroite();

    /**
     * Permet à l'entite de se déplacer en diagonale en haut à gauche
     */
    void seDeplaceEnHautAGauche();

    /**
     * Permet à l'entite de se déplacer en diagonale en bas à gauche
     */
    void seDeplaceEnBasAGauche();
};


#endif //ROBOT_ECRASEUR_MOUVANTE_H
