//
// Created by totoo on 03/12/2019.
//

#include <fstream>
#include <persistance.h>
#include "../header/game.h"
#include "joueur.h"
#include "robot.h"

using namespace std;

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
        //robot r{};
        //d_entite.push_back(r);
    }
}