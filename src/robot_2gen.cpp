//
// Created by totoo on 09/11/2019.
//


#include <vector>
#include "../header/robot_2gen.h"

robot_2gen::robot_2gen(int x, int y):robot(x,y) {
    d_type=ROBOT_2GEN;
}

void robot_2gen::deplacement_Auto(joueur *j) {
    std::vector<int> scoreDeplacement;

    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->getPosition().getPosX())
                                   + abs(d_pos.getPosY() - j->getPosition().getPosY());

    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                 + abs(d_pos.getPosY() + 1 - j->getPosition().getPosY());

    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->getPosition().getPosX())
                                + abs(d_pos.getPosY() -1 - j->getPosition().getPosY());

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

    for(int i=1; i < scoreDeplacement.size(); ++i)
    {
        if(meilleurScore > scoreDeplacement.at(i))
        {
            meilleurScore = scoreDeplacement.at(i);
            indexMeilleurScore = i;
        }
    }

    switch(indexMeilleurScore)
    {
        case DROITE_DEPLACEMENT :
            seDeplaceADroite();
            break;
        case GAUCHE_DEPLACEMENT :
            seDeplaceAGauche();
            break;
        case HAUT_DEPLACEMENT :
            seDeplaceEnHaut();
            break;
        case BAS_DEPLACEMENT :
            seDeplaceEnBas();
            break;
        case BAS_GAUCHE_DEPLACEMENT:
            seDeplaceEnBasAGauche();
            break;
        case BAS_DROITE_DEPLACEMENT:
            seDeplaceEnBasADroite();
            break;
        case HAUT_GAUCHE_DEPLACEMENT:
            seDeplaceEnHautAGauche();
            break;
        case HAUT_DROITE_DEPLACEMENT:
            seDeplaceEnHautADroite();
            break;
        default:
            break;
    }
}