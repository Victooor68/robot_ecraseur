//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_GAME_H
#define ROBOT_ECRASEUR_GAME_H


#include "terrain.h"
#include "entite.h"
#include "joueur.h"
#include "debris.h"
#include "robot_1gen.h"
#include "robot_2gen.h"

class game {
public:
    game();
    void init();
    void run(std::ostream & ost,std::istream & ist);
    void saveGame(std::string fileName);
    void restoreGame(std::string fileName);

private:
    terrain d_terrain;
    joueur d_joueur;
    std::vector<debris> d_debris;
    std::vector<robot_1gen> d_robot1;
    std::vector<robot_2gen> d_robot2;
    void restoreEntiteDeTerrain(terrain terrain);
    joueur joueurSelonDifficulte(char difficulte, std::string string);
    void generationDesRobotsAleatoire(int nbRobotGen1, int nbRobotGen2);

    void generationAleatoireDebris(int debris);

    void collisionApresDeplacement(int direction, joueur *pJoueur);


    void collisionApresDeplcement(int direction, robot *gen, int i);
};


#endif //ROBOT_ECRASEUR_GAME_H
