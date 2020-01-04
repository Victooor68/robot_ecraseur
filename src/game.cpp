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
const char QUIT_GAME ='Q';
const char SAVE = 'S';
const char RESTORE = 'R';
const char MOUVEMENT = 'M';
using namespace std;



game::game() : d_terrain{terrain{10,10}},d_joueur{-1,-1,"default"} ,d_debris{}
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
    int nbRobotGen1, nbRobotGen2;
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

   generationDesRobotsAleatoire(nbRobotGen1, nbRobotGen2);

   d_terrain.affiche(ost);

   joueur* j = &d_joueur;

   // déroulement du jeu
   while (again)
   {
       char commande;

       ost<<"Commande : "<<endl;
       ist>>commande;

       if(d_terrain.deplacement(commande-48,j))
       {
           // deplacement des robots
           for (int i = 0; i < d_robot.size(); ++i)
           {
               d_terrain.deplacementRobotAuto(d_robot.at(i), j);
           }
       } else
       {
           switch(commande)
           {
               case QUIT_GAME:
                   return;
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

       if(d_robot.size() == 0){ // fin du jeu, gagner car 0 robot
           again = false;
       }
   }
}



void game::restoreEntiteDeTerrain(terrain terrain)
{    for (int i = 0; i <terrain.hauteur() ; ++i) {
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
                    d_robot.push_back(&r);
                }
                else{
                    robot_2gen r{x, y};
                    d_terrain.ajoutDansTerrain(r);
                    d_robot.push_back(&r);
                }

                impossible = false;
            }
        }
    }
}

int game::doDirection( std::ostream &ost, std::istream &ist) {

    int direction;
    bool directionIncorrect = true;
    while(directionIncorrect){
        ost<<"Direction ?"<<endl;
        ist>>direction;
            if(direction == BAS || direction == BAS_DROITE || direction == BAS_GAUCHE || direction == GAUCHE
               || direction == DROITE || direction == HAUT || direction == HAUT_GAUCHE || direction == HAUT_DROITE){
                directionIncorrect = false;
            }
            else{
                ost<<"Error : Veuillez saisir un chiffre entre 1 et 9"<<endl;
            }
        }
    return direction;
}

