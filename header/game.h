//
// Created by totoo on 03/12/2019.
//

#ifndef ROBOT_ECRASEUR_GAME_H
#define ROBOT_ECRASEUR_GAME_H


#include "terrain.h"
#include "entite.h"
#include "joueur.h"

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
    std::vector<entite> d_entite;
    std::vector<robot*> d_robot;
    std::vector<entite> restoreEntiteDeTerrain(terrain terrain);
    joueur joueurSelonDifficulte(char difficulte, std::string string);
    void generationDesRobotsAleatoire(int nbRobotGen1, int nbRobotGen2);
};


#endif //ROBOT_ECRASEUR_GAME_H
