//
// Created by totoo on 09/11/2019.
//


#include "../header/robot_1gen.h"

robot_1gen::robot_1gen(int x, int y):robot(x,y) {
    d_type= ROBOT_1GEN;
}

position robot_1gen::meilleurDeplacement(joueur *j) {
    int score_Deplacement_Droite = abs(d_pos.getPosX() + 1 - j->position().getPosX())
            + abs(d_pos.getPosY() - j->position().getPosX());
    int score_Deplacement_Gauche = abs(d_pos.getPosX() - 1 - j->position().getPosX())
                                   + abs(d_pos.getPosY() - j->position().getPosX());
    int score_Deplacement_Haut = abs(d_pos.getPosX() - j->position().getPosX())
                                 + abs(d_pos.getPosY() + 1 - j->position().getPosX());
    int score_Deplacement_Bas = abs(d_pos.getPosX() - j->position().getPosX())
                               + abs(d_pos.getPosY() -1 - j->position().getPosX());
}