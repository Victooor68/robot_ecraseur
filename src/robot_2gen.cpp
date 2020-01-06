//
// Created by totoo on 09/11/2019.
//


#include <vector>
#include "terrain.h"
#include "../header/robot_2gen.h"

robot_2gen::robot_2gen(int x, int y):robot(x,y) {
    d_type=ROBOT_2GEN;
}

int robot_2gen::deplacement_Auto(joueur *j) {
    std::vector<int> scoreDeplacement;

    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                 + abs(d_pos.getPosY() - 1 - j->getPosition().getPosY());

    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                + abs(d_pos.getPosY() +1 - j->getPosition().getPosY());

    int score_Deplacement_Bas_Gauche = abs(d_pos.getPosX() -1 - j->getPosition().getPosX())
                                       + abs(d_pos.getPosY() +1 - j->getPosition().getPosY());

    int score_Deplacement_Bas_Droite = abs(d_pos.getPosX() +1 - j->getPosition().getPosX())
                                       + abs(d_pos.getPosY() +1 - j->getPosition().getPosY());

    int score_Deplacement_Haut_Gauche = abs(d_pos.getPosX() -1 - j->getPosition().getPosX())
                                        + abs(d_pos.getPosY() -1 - j->getPosition().getPosY());

    int score_Deplacement_Haut_Droite = abs(d_pos.getPosX() +1 - j->getPosition().getPosX())
                                        + abs(d_pos.getPosY() -1 - j->getPosition().getPosY());

    scoreDeplacement.push_back(score_Deplacement_Droite);
    scoreDeplacement.push_back(score_Deplacement_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Haut);
    scoreDeplacement.push_back(score_Deplacement_Bas);
    scoreDeplacement.push_back(score_Deplacement_Bas_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Bas_Droite);
    scoreDeplacement.push_back(score_Deplacement_Haut_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Haut_Droite);

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
        case HAUT_DROITE_DEPLACEMENT:
            return HAUT_DROITE;
        case BAS_DROITE_DEPLACEMENT:
            return BAS_DROITE;
        case HAUT_GAUCHE_DEPLACEMENT:
            return HAUT_GAUCHE;
        case BAS_GAUCHE_DEPLACEMENT:
            return BAS_GAUCHE;
        default:
            return -1;
    }
}