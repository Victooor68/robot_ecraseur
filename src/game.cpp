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

const char DIFFICULTE_EXPERT = 'E';
const char DIFFICULTE_NORMAL = 'N';

using namespace std;



game::game() : d_terrain{terrain{10,10}},d_joueur{-1,-1,"default"} ,d_entite{}
{
   // init();
}

void game::saveGame(std::string fileName) {
    std::ofstream myFile(fileName);
    persistance::sauve(myFile,d_terrain);
    myFile.close();
}

void game::restoreGame(std::string fileName) {
    std::ifstream myFile(fileName);
    d_terrain=persistance::restore(myFile);
    myFile.close();
    d_entite=restoreEntiteDeTerrain(d_terrain);
}

void game::run(std::ostream &ost, std::istream &ist) {
    int nbRobotGen1, nbRobotGen2;
    string nomJoueur;
    char difficulte;
    bool again=true;

    ost<<"Combien de Robot generation 1 ?"<<endl;
    ist>>nbRobotGen1;

    ost<<"Combien de Robot generation 2 ?"<<endl;
    ist>>nbRobotGen2;

    ost<<"Nom du joueur :"<<endl;
    ist>>nomJoueur;

    ost<<"Difficulté Expert ou Normal(E or N) ?";
    ist>>difficulte;

   d_joueur=joueurSelonDifficulte(difficulte, nomJoueur);
   d_terrain.ajoutDansTerrain(d_joueur);

   generationDesRobotsAleatoire(nbRobotGen1, nbRobotGen2);

   d_terrain.affiche(ost);

   entiteMouvante* mouv = &d_joueur;

   while (again)
   {
       bool directionIncorrect = true;
       int direction;

       while(directionIncorrect){
           ost<<"Direction ?"<<endl;
           ist>>direction;
           if(isdigit(direction))
           {
               if(direction == BAS || direction == BAS_DROITE || direction == BAS_GAUCHE || direction == GAUCHE || direction == DROITE || direction == HAUT || direction == HAUT_GAUCHE || direction == HAUT_DROITE){
                   directionIncorrect = false;
               }
               else{
                   ost<<"Error : Veuillez saisir un chiffre entre 1 et 9"<<endl;
               }
           }
           else{
               ost<<"Error : Veuillez saisir un chiffre"<<endl;
           }
       }
       d_terrain.deplacement(direction,mouv);
       for (int i = 0; i < d_entite.size(); ++i) {
           if(d_entite.at(i).getType() == ROBOT_1GEN) {
               d_terrain.deplacementRobotGen1Auto(&d_entite.at(i), mouv);
           }
           if(d_entite.at(i).getType() == ROBOT_2GEN) {
               d_terrain.deplacementRobotGen1Auto(&d_entite.at(i), mouv);
           }
       }
       d_terrain.affiche(ost);
   }
}



std::vector<entite> game::restoreEntiteDeTerrain(terrain terrain)
{
    std::vector<entite> entite;

    for (int i = 0; i <terrain.hauteur() ; ++i) {
        for (int j = 0; j <terrain.largeur() ; ++j) {
            int typeCase=terrain.getCase(i,j);
            switch(typeCase){
                case VIDE :
                    break;
                case ROBOT_1GEN :
                    break;
                case ROBOT_2GEN :
                    break;
                case JOUEUR_NORMAL :
                    break;
                case JOUEUR_EXPERT :
                    break;
                case DEBRIS :
                    break;
            }
        }
    }

    return entite;
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
    int nbRobot = nbRobotGen1 + nbRobotGen2;
    for(int i = 0; i<nbRobot; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() %d_terrain.largeur();
            int y = rand() %d_terrain.hauteur();
            if(d_terrain.estVide(x,y)) {
                if((nbRobotGen1 - i) >= 0){
                    robot_1gen r{x, y};
                    d_terrain.ajoutDansTerrain(r);
                    d_entite.push_back(r);
                }
                else{
                    robot_2gen r{x, y};
                    d_terrain.ajoutDansTerrain(r);
                    d_entite.push_back(r);
                }

                impossible = false;
            }
        }
    }
}
