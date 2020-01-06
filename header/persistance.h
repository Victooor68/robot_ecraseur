//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_PERSISTANCE_H
#define ROBOT_ECRASEUR_PERSISTANCE_H


#include <iosfwd>
#include "doctest.h"
#include "terrain.h"

class persistance {
public:
    /**
     * Sauve le terrain donne en parametre dans un fichier
     * @param f
     * @param t
     */
    void static sauve(std::ofstream &f,terrain t);

    /**
     * Renvoie un terrain a partir d'un fichier
     * @param is
     * @return terainRestaure
     */
    static terrain restore(std::ifstream &is);
};


#endif //ROBOT_ECRASEUR_PERSISTANCE_H
