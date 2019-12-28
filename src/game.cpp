//
// Created by totoo on 03/12/2019.
//

#include <fstream>
#include <persistance.h>
#include "../header/game.h"
#include "joueur.h"
#include "robot_1gen.h"

using namespace std;

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
    for(int i = 0; i<nbRobot; i++){
        bool impossible = true;
        while(impossible){
            int x, y;
            x = rand();
            if(d_terrain.estVide(0,0)) {
                robot_1gen r{0, 0};
                d_terrain.ajoutDansTerrain(r);
                d_entite.push_back(r);
            }
        }
    }
    //d_terrain.setDTerrain(d_entite);
}