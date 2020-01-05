//
// Created by totoo on 03/12/2019.
//

#include <fstream>
#include <persistance.h>
#include "../header/game.h"
#include "joueur.h"
#include "joueurExpert.h"
#include "joueurNormal.h"
#include "robot_1gen.h"
#include "robot_2gen.h"
#include "debris.h"

const char DIFFICULTE_EXPERT = 'E';
const char DIFFICULTE_NORMAL = 'N';
const char QUIT_GAME ='Q';
const char SAVE = 'S';
const char RESTORE = 'R';

using namespace std;



game::game() : d_terrain{terrain{10,10}},d_joueur{-1,-1,"default"} ,d_debris{},d_robot1{},d_robot2{}
{}

void game::saveGame(std::string fileName) {
    std::ofstream myFile(fileName);
    persistance::sauve(myFile,d_terrain);
    myFile.close();
}

void game::restoreGame(std::string fileName) {
    std::ifstream myFile(fileName);
    d_terrain=persistance::restore(myFile);
    myFile.close();
    restoreEntiteDeTerrain(d_terrain);
}

void game::run(std::ostream &ost, std::istream &ist) {
    int nbRobotGen1, nbRobotGen2,nbDebris;
    string nomJoueur,nomFichier;
    char difficulte;
    bool again=true;

    ost<<"Combien de Robot generation 1 ?"<<endl;
    ist>>nbRobotGen1;

    ost<<"Combien de Robot generation 2 ?"<<endl;
    ist>>nbRobotGen2;

    ost<<"Nom du joueur :"<<endl;
    ist>>nomJoueur;

    ost<<"Difficult Expert ou Normal (E or N) ?";
    ist>>difficulte;

   d_joueur = joueurSelonDifficulte(difficulte, nomJoueur);
   d_terrain.ajoutDansTerrain(d_joueur);

   ost<<"Combien de debris sur le terrain ? "<<endl;
   ist>>nbDebris;

   generationAleatoireDebris(nbDebris);

   generationDesRobotsAleatoire(nbRobotGen1, nbRobotGen2);

   d_terrain.affiche(ost);

    joueur* joueur = &d_joueur;

    // déroulement du jeu
    while (again)
    {
        char commande;

        ost<<"Commande : "<<endl;
        ist>>commande;

        if(d_terrain.deplacement(commande-48,joueur))
        {

            // deplacement des robots
            for (int i = 0; i < d_robot1.size(); ++i)
            {
               d_terrain.deplacement(d_robot1.at(i).deplacement_Auto(joueur), &d_robot1.at(i));
            }
            for (int i = 0; i < d_robot2.size(); ++i)
            {
                d_terrain.deplacement(d_robot2.at(i).deplacement_Auto(joueur), &d_robot2.at(i));
            }
        } else
       {
           switch(commande)
           {
               case QUIT_GAME:
                   again= false;
               case SAVE:
                   ost<<"Nom du fichier ?";
                   ist>>nomFichier;
                   this->saveGame(nomFichier);
                   break;
               case RESTORE:
                   ost<<"Nom du fichier ?";
                   ist>>nomFichier;
                   this->restoreGame(nomFichier);
                   break;
           }
       }

       d_terrain.affiche(ost);

       if(d_robot1.size() == 0&&d_robot2.size()==0){ // fin du jeu, gagner car 0 robot
           again = false;
       }
   }
}



void game::restoreEntiteDeTerrain(terrain terrain)
{
    joueurExpert je {0,0,d_joueur.Nom()};

    for (int i = 0; i <terrain.hauteur() ; ++i) {
        for (int j = 0; j <terrain.largeur() ; ++j) {
            int typeCase=terrain.getCase(i,j);
            if (typeCase==JOUEUR_NORMAL)
           {
               joueurNormal joueurNormal{i,j,d_joueur.Nom()};
               d_joueur=joueurNormal;
           } else if (typeCase==JOUEUR_EXPERT)
           {
               joueurExpert joueurExpert{i,j,d_joueur.Nom()};
               d_joueur=joueurExpert;
           } else if (typeCase==ROBOT_1GEN){
               robot_1gen robot1Gen{i,j};
               d_robot1.clear();
               d_robot1.push_back(robot1Gen);
           } else if (typeCase==ROBOT_2GEN){
                robot_2gen robot2Gen{i,j};
                d_robot2.clear();
                d_robot2.push_back(robot2Gen);
           }else if (typeCase==DEBRIS){
               debris debris{i,j};
               d_debris.clear();
               d_debris.push_back(debris);
           }
        }
    }
}

joueur game::joueurSelonDifficulte(char difficulte, std::string nomJoueur) {

    if (difficulte == DIFFICULTE_NORMAL){
        joueurNormal playerNormal{(d_terrain.largeur()/2), d_terrain.hauteur()/2,nomJoueur};
        return  playerNormal;
    } else{
        if (difficulte == DIFFICULTE_EXPERT){
            joueurExpert playerExpert{(d_terrain.largeur()/2), d_terrain.hauteur()/2,nomJoueur};
            return playerExpert;
        }else{
            joueur j{1,1,nomJoueur} ;
            return  j ;
        }
    }
}

void game::generationDesRobotsAleatoire(int nbRobotGen1, int nbRobotGen2) {

    for(int i = 0; i<nbRobotGen1; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() %d_terrain.largeur();
            int y = rand() %d_terrain.hauteur();
            if(d_terrain.estVide(x,y)) {
                    robot_1gen r{x, y};
                    d_terrain.ajoutDansTerrain(r);
                    d_robot1.push_back(r);

                impossible = false;
            }
        }
    }

    for(int i = 0; i<nbRobotGen2; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() %d_terrain.largeur();
            int y = rand() %d_terrain.hauteur();
            if(d_terrain.estVide(x,y)) {
                    robot_2gen r{x, y};
                    d_terrain.ajoutDansTerrain(r);
                    d_robot2.push_back(r);
                }
                impossible = false;
            }
        }
    }

void game::generationAleatoireDebris(int nbDebris) {

    for(int i = 0; i<nbDebris; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() %d_terrain.largeur();
            int y = rand() %d_terrain.hauteur();
            if(d_terrain.estVide(x,y)) {
                debris debris {x,y};
                d_terrain.ajoutDansTerrain(debris);
                d_debris.push_back(debris);

                impossible = false;
            }
        }
    }
}



