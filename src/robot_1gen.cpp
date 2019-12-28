//
// Created by totoo on 09/11/2019.
//

#include "position.hpp"
#include <vector>
#include "../header/robot_1gen.h"


robot_1gen::robot_1gen(int x, int y):robot(x,y) {
    d_type= ROBOT_1GEN;
}

void robot_1gen::deplacement_Auto(joueur *j) {
    std::vector<int> scoreDeplacement;

    //index DROITE_DEPLACEMENT
    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->position().getPosX())
            + abs(d_pos.getPosY() - j->position().getPosY());
    //index GAUCHE_DEPLACEMENT
    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->position().getPosX())
                                   + abs(d_pos.getPosY() - j->position().getPosY());
    //index HAUT_DEPLACEMENT
    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->position().getPosX())
                                 + abs(d_pos.getPosY() + 1 - j->position().getPosY());
    //index BAS_DEPLACEMENT
    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->position().getPosX())
                               + abs(d_pos.getPosY() -1 - j->position().getPosY());

    scoreDeplacement.push_back(score_Deplacement_Droite);
    scoreDeplacement.push_back(score_Deplacement_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Haut);
    scoreDeplacement.push_back(score_Deplacement_Bas);

    int meilleurScore = score_Deplacement_Haut;
    int indexMeilleurScore = 0;

    for(int i=1; i < scoreDeplacement.size(); ++i)
    {
        if(meilleurScore > scoreDeplacement.at(i))
        {
            meilleurScore = scoreDeplacement.at(i);
            indexMeilleurScore = i;
        }
    }

    switch(indexMeilleurScore) {
        case DROITE_DEPLACEMENT : seDeplaceADroite();
        case GAUCHE_DEPLACEMENT : seDeplaceAGauche();
        case HAUT_DEPLACEMENT : seDeplaceEnHaut();
        case BAS_DEPLACEMENT : seDeplaceEnBas();
    }

}