//
// Created by totoo on 03/12/2019.
//

#include <fstream>
#include <persistance.h>
#include "../header/game.h"
#include "joueur.h"
#include "robot_1gen.h"

using namespace std;

const int VID1E= 0;

game::game() : d_terrain{terrain{10,10}}{
    init();
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
