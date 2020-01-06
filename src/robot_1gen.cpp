//
// Created by totoo on 09/11/2019.
//

#include "position.hpp"
#include <vector>
#include "../header/robot_1gen.h"
#include "terrain.h"


robot_1gen::robot_1gen(int x, int y) : robot(x,y) {
    d_type= ROBOT_1GEN;
}

int robot_1gen::deplacement_Auto(joueur* j) {
    std::vector<int> scoreDeplacement;

    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->getPosition().getPosX())
            + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                 + abs(d_pos.getPosY() - 1 - j->getPosition().getPosY());

    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->getPosition().getPosX())
                               + abs(d_pos.getPosY() +1 - j->getPosition().getPosY());

    scoreDeplacement.push_back(score_Deplacement_Droite);
    scoreDeplacement.push_back(score_Deplacement_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Haut);
    scoreDeplacement.push_back(score_Deplacement_Bas);

    int meilleurScore = score_Deplacement_Droite;
    int indexMeilleurScore = 0;

    for(int i=0; i < scoreDeplacement.size(); ++i)
    {
        if(meilleurScore > scoreDeplacement.at(i))
        {
            meilleurScore = scoreDeplacement.at(i);
            indexMeilleurScore = i;
        }
    }

    switch(indexMeilleurScore)
    {
        case BAS_DEPLACEMENT :
            return BAS;
        case HAUT_DEPLACEMENT :
            return HAUT;
        case GAUCHE_DEPLACEMENT :
            return GAUCHE;
        case DROITE_DEPLACEMENT :
            return DROITE;
        default:
            return -1;
    }

}