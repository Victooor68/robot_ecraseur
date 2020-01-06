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
    int nbRobotGen1, nbRobotGen2,nbDebris, score = 0;
    string nomJoueur,nomFichier;
    char difficulte;
    bool again=true;

    ost<<"\n";
    ost<<"---------------------------------------------------------"<<endl;
    ost<<"---------------  ROBOT ECRASEUR GAME 1.0  ---------------"<<endl;
    ost<<"---------------------------------------------------------"<<endl;

    ost<<"\nCommandes :"<<endl;
    ost<<"\t- Utilisez le pave numerique pour vous deplacez"<<endl;
    ost<<"\t- Quit game : Q"<<endl;
    ost<<"\t- Save game : S"<<endl;
    ost<<"\t- Restore game : R"<<endl;

    ost<<"\nCombien de robot generation 1 ?"<<endl;
    ist>>nbRobotGen1;

    ost<<"Combien de robot generation 2 ?"<<endl;
    ist>>nbRobotGen2;

    ost<<"Combien de debris sur le terrain ? "<<endl;
    ist>>nbDebris;

    ost<<"Nom du joueur :"<<endl;
    ist>>nomJoueur;

    ost<<"Difficulte : expert ou normal (E or N) ?"<<endl;
    ist>>difficulte;

   d_joueur = joueurSelonDifficulte(difficulte, nomJoueur);
   d_terrain.ajoutDansTerrain(d_joueur);

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

        if((isdigit(commande)))
        {
            int direction = commande-48;
            collisionApresDeplacementJoueur(direction, joueur);
            d_terrain.deplacement(direction,joueur);
            score+= 5;
            // deplacement des robots
            for (int i = 0; i < d_robot1.size(); ++i)
            {
                direction=d_robot1.at(i).deplacement_Auto(joueur);
                if (!collisionApresDeplacement(direction, &d_robot1.at(i), i)){
                    d_terrain.deplacement(direction, &d_robot1.at(i));
                } else
                {
                    score+=15;
                }
            }
            for (int i = 0; i < d_robot2.size(); ++i)
            {
                direction=d_robot2.at(i).deplacement_Auto(joueur);
                if(!collisionApresDeplacement(direction, &d_robot2.at(i), i)){
                    d_terrain.deplacement(direction, &d_robot2.at(i));
                }
                score+=25;
            }
        } else
       {
           switch(commande)
           {
               case QUIT_GAME:
                   again= false;
                   break;
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

       if(d_robot1.size() == 0 && d_robot2.size()==0||!d_joueur.enVie()) // fin du jeu, gagner car 0 robot
       {
           again = false;
       }
    }

    ost<<"\n"<<endl;
    ost<<"---------------------------------------------------------"<<endl;
    if(joueur->enVie())
    {
        ost<<"--------------------  !!! YOU WIN !!! -------------------"<<endl;
    } else
    {
        ost<<"-------------------  !!! GAME OVER !!! ------------------"<<endl;
    }
    ost<<"---------------------------------------------------------"<<endl;
    ost<<"|| Score : "<<score<<" ||";

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
            joueurNormal j{1,1,nomJoueur} ;
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

void game::collisionApresDeplacementJoueur(int direction, joueur *joueur) {
    int typeCaseDansDirection= d_terrain.typeSelonDirection(direction, joueur->getPosition());

    if (typeCaseDansDirection!=VIDE){
    joueur->meurt();
    }

}

bool game::collisionApresDeplacement(int direction, robot *robotEffectuantLeDeplacement, int indexRobotDansVector) {
    int typeCaseDansDirection= d_terrain.typeSelonDirection(direction, robotEffectuantLeDeplacement->getPosition());
    bool collision=false;
    if (typeCaseDansDirection==ROBOT_2GEN||typeCaseDansDirection==ROBOT_1GEN){

        position positionEntite = d_terrain.getPositionDansDirection(robotEffectuantLeDeplacement->getPosition(), direction);
        for (int j = 0; j <d_robot1.size() ; ++j) {
            if (d_robot1.at(indexRobotDansVector).getPosition() == positionEntite){
                destructionRobot(&d_robot1.at(j), j);
            }
        }
        for (int k = 0; k <d_robot2.size() ; ++k) {
            if (d_robot2.at(indexRobotDansVector).getPosition() == positionEntite){
                destructionRobot(&d_robot2.at(k), k);
            }
        }

        debris debrisCollision{positionEntite.getPosY(), positionEntite.getPosX()};

        d_terrain.ajoutDansTerrain(debrisCollision);
        d_debris.push_back(debrisCollision);

        destructionRobot(robotEffectuantLeDeplacement, indexRobotDansVector);

        collision=true;
    } else if (typeCaseDansDirection==DEBRIS){
        destructionRobot(robotEffectuantLeDeplacement, indexRobotDansVector);
        collision= true;
    } else if (typeCaseDansDirection==JOUEUR_EXPERT||typeCaseDansDirection==JOUEUR_NORMAL){
        d_joueur.meurt();
    }
    return collision;
}

void game::destructionRobot(robot *pRobot, int indexRobotDansVector) {
    if (pRobot->getType() == ROBOT_1GEN){
        d_terrain.enleveEntiteTerrain(pRobot);
        d_robot1.erase(d_robot1.begin() + indexRobotDansVector);
    }
    else{
        d_terrain.enleveEntiteTerrain(pRobot);
        d_robot2.erase(d_robot2.begin() + indexRobotDansVector);
    }
}


