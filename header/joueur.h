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
    std::string Nom() const;
    bool enVie()const;
    void meurt();
private:
    std::string d_name;
    bool d_enVie;
};


#endif //ROBOT_ECRASEUR_JOUEUR_H
