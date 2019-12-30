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

void game::init(){
    double nbRobot;
    string nomJoueur;
    cout<<"Combien de robot ?"<<endl;
    cin>>nbRobot;
    cout<<"Nom du joueur :"<<endl;
    cin>>nomJoueur;
    joueur j{(d_terrain.largeur()/2), d_terrain.hauteur()/2, nomJoueur};
    d_entite.push_back(j);
    d_terrain.ajoutDansTerrain(j);
    for(int i = 0; i<nbRobot; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() % ((d_terrain.largeur() - 0) + 1) + 0;
            int y = rand() % ((d_terrain.hauteur() - 0) + 1) + 0;
            if(d_terrain.estVide(x,y)) {
                robot_1gen r{x, y};
                d_terrain.ajoutDansTerrain(r);
                d_entite.push_back(r);
                impossible = false;
            }
        }
    }
}

void game::run(std::ostream &ost, std::istream &ist) {
    int nbRobot;
    string nomJoueur;
    char difficulte;
    bool again=true;

    ost<<"Combien de Robot ?"<<endl;
    ist>>nbRobot;

    ost<<"Nom du joueur :"<<endl;
    ist>>nomJoueur;

    ost<<"Difficulté Expert ou Normal(E or N) ?";
    ist>>difficulte;

   d_joueur=joueurSelonDifficulte(difficulte, nomJoueur);
   d_terrain.ajoutDansTerrain(d_joueur);

   generationDesRobotsAleatoire(nbRobot);

   d_terrain.affiche(ost);

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

void game::generationDesRobotsAleatoire(int nbRobot) {
    for(int i = 0; i<nbRobot; i++){
        bool impossible = true;
        while(impossible){
            int x = rand() %d_terrain.largeur();
            int y = rand() %d_terrain.hauteur();
            if(d_terrain.estVide(x,y)) {
                robot_1gen r{x, y};
                d_terrain.ajoutDansTerrain(r);
                d_entite.push_back(r);
                impossible = false;
            }
        }
    }
}
