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
    /**
     * Creer une entite a partir de x et y
     * @param x
     * @param y
     */
    entite(int x, int y);
    /**
     * Creer une entite a partir d'une position
     * @param position
     */
    entite(const position& position);
    ~entite();
    /**
     * Renvoie la position de l'entite
     * @return position
     */
    position getPosition() const;
    /**
     * Renvoie le type de l'entite
     * @return type
     * @return type
     */
    int getType() const;

protected:
    position d_pos;
    int d_type;
};

#endif //ROBOT_ECRASEUR_ENTITE_H
