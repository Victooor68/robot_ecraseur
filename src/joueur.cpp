//
// Created by totoo on 09/11/2019.
//


#include <string>
#include "../header/joueur.h"

joueur::joueur(int x, int y, std::string nom):entiteMouvante{x,y},d_name{nom}
{}

std::string joueur::Nom()const
{
    return d_name;
}