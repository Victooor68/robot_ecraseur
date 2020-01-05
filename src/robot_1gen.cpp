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
    std::cout<<"Deplacement Droite : "<<score_Deplacement_Droite<<std::endl;

    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());
    std::cout<<"Deplacement Gauche : "<<score_Deplacement_Gauche<<std::endl;

    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                 + abs(d_pos.getPosY() - 1 - j->getPosition().getPosY());
    std::cout<<"Deplacement Haut : "<<score_Deplacement_Haut<<std::endl;

    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->getPosition().getPosX())
                               + abs(d_pos.getPosY() +1 - j->getPosition().getPosY());
    std::cout<<"Deplacement Bas : "<<score_Deplacement_Bas<<std::endl;

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
    std::cout<<"Meilleure score = "<<meilleurScore<<std::endl;
    std::cout<<"Index : "<<indexMeilleurScore<<std::endl;

    switch(indexMeilleurScore)
    {
        case DROITE_DEPLACEMENT :
            //seDeplaceADroite();
            return DROITE;
        case GAUCHE_DEPLACEMENT :
            //seDeplaceAGauche();
            return GAUCHE;
        case HAUT_DEPLACEMENT :
            //seDeplaceEnHaut();
            return HAUT;
        case BAS_DEPLACEMENT :
            //seDeplaceEnBas();
            return BAS;
        default:
            return -1;
    }

}