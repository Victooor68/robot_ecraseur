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

    //index DROITE
    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->position().getPosX())
            + abs(d_pos.getPosY() - j->position().getPosX());
    //index GAUCHE
    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->position().getPosX())
                                   + abs(d_pos.getPosY() - j->position().getPosX());
    //index HAUT
    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->position().getPosX())
                                 + abs(d_pos.getPosY() + 1 - j->position().getPosX());
    //index BAS
    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->position().getPosX())
                               + abs(d_pos.getPosY() -1 - j->position().getPosX());

    scoreDeplacement.push_back(score_Deplacement_Droite);
    scoreDeplacement.push_back(score_Deplacement_Gauche);
    scoreDeplacement.push_back(score_Deplacement_Haut);
    scoreDeplacement.push_back(score_Deplacement_Bas);

    int meilleurScore = score_Deplacement_Haut;
    int indexMeilleurScore = 1;

    for(int i=2; i <= scoreDeplacement.size(); ++i)
    {
        if(meilleurScore < scoreDeplacement.at(i))
        {
            meilleurScore = scoreDeplacement.at(i);
            indexMeilleurScore = i;
        }
    }

    switch(indexMeilleurScore) {
        case DROITE : seDeplaceADroite();
        case GAUCHE : seDeplaceAGauche();
        case HAUT : seDeplaceEnHaut();
        case BAS : seDeplaceEnBas();
    }

}