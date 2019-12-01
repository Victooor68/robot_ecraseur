//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_JOUEUR_H
#define ROBOT_ECRASEUR_JOUEUR_H

#include "entiteMouvante.h"

class joueur : public entiteMouvante {
public:
    joueur(string nom);
    string Nom() const;
private:
    string d_name;
};


#endif //ROBOT_ECRASEUR_JOUEUR_H
