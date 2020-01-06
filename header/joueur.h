//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_JOUEUR_H
#define ROBOT_ECRASEUR_JOUEUR_H

#include "entiteMouvante.h"
#include <string>

class joueur : public entiteMouvante {

public:
    joueur(int x, int y, std::string nom);
    /**
     * renvoie le nom du joueur
     * @return
     */
    std::string Nom() const;

    /**
     * renvoie l'etat de sante du joueur ( en vie ou non)
     * @return
     */
    bool enVie()const;

    /**
     * methode mettant l'etat de santé du joueur (enVie) a false
     */
    void meurt();

private:
    std::string d_name;
    bool d_enVie;
};


#endif //ROBOT_ECRASEUR_JOUEUR_H
