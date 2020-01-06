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
    /**
     * constructeur par defaut de la classe game
     */
    game();

    /**
     * methode executant le deroulement du jeu avec un affichage
     * @param ost
     * @param ist
     */
    void run(std::ostream & ost,std::istream & ist);

    /**
     * methode permettant de sauvegarder une partie
     * @param fileName
     */
    void saveGame(std::string fileName);

    /**
     * merthode permettant la restoration totale d'une partie a partir d'un nom de fichier
     * @param fileName
     */
    void restoreGame(std::string fileName);

private:

    terrain d_terrain;
    joueur d_joueur;
    std::vector<debris> d_debris;
    std::vector<robot_1gen> d_robot1;
    std::vector<robot_2gen> d_robot2;

    /**
     * a partir d'un terrain restaure les entité présent dans game
     * @param terrain
     */
    void restoreEntiteDeTerrain(terrain terrain);

    /**
     * methode retournant un joueur selon la difficulte passe en parametre
     * @param difficulte
     * @param string
     * @return joueur selon difficulte (E ou N)
     */
    joueur joueurSelonDifficulte(char difficulte, std::string string);

    /**
     * methode generant a des places aléatoire des robots de 1 Gen et 2 Gen et modifiant le terrain
     */
    void generationDesRobotsAleatoire(int nbRobotGen1, int nbRobotGen2);

    /**
     * methode genere et place aleatoirement un nombre nbDebris de debris
     * @param nbDebris
     */
    void generationAleatoireDebris(int nbDebris);


    /**
     * Methode calculant la case d'arrive d'un joueur et le tue si ce n'est pas une case VIDE
     * @param direction
     * @param joueur
     */
    void collisionApresDeplacementJoueur(int direction, joueur *joueur);


    /**
     * Methode calculant la case d'arrive d'un robot et gere les collisions eventuel
     * @param direction
     * @param robotEffectuantLeDeplacement
     * @param indexRobotDansVector
     * @return
     */
    bool collisionApresDeplacement(int direction, robot *robotEffectuantLeDeplacement, int indexRobotDansVector);

    /**
     * detruit le robot passe en parametre a l'index donne
     * @param pRobot
     * @param indexRobotDansVector
     */
    void destructionRobot(robot *pRobot, int indexRobotDansVector);
};


#endif //ROBOT_ECRASEUR_GAME_H
