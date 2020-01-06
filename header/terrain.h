#ifndef TERRAIN_H
#define TERRAIN_H

#include "entite.h"
#include "entiteMouvante.h"
#include <vector>
#include <iostream>
#include "robot.h"
#include "joueur.h"

#define HAUT_DROITE 9
#define DROITE 6
#define BAS_DROITE 3
#define HAUT 8
#define BAS 2
#define HAUT_GAUCHE 7
#define GAUCHE 4
#define BAS_GAUCHE 1


class terrain
{
public:
    /**
     * Creer un terrain à partir des paramètres hauteur et largeur
     * @param largeur
     * @param hauteur
     */
    terrain(int largeur, int hauteur);
    /**
     * Creer un terrain à partir d'un autre terrain
     * @param terrain
     */
    terrain( std::vector<std::vector<int>> terrain);
    virtual ~terrain();
    void setTerrain(const std::vector<std::vector<int>> terrain);
    /**
     * Ajoute une entite dans le terrain
     * @param ent
     */
    void ajoutDansTerrain(const entite& ent);
    /**
     * Renvoie le tableau 2D du terrain
     */
    std::vector<std::vector<int>> getTerrain() const;
    /**
     * Affiche le terrain
     * @param os
     */
    void affiche(std::ostream& os) const;
    /**
     * Affiche le terrain graphiquement
     */
    void afficheGraphique() const;
    int largeur() const;
    int hauteur() const;
    /**
     * Return true l'entite reste dans le terrain si elle va dans la direction donne en parametre
     * @param ent
     * @param direction
     */
    bool estDansTerrain(entiteMouvante* ent, int direction) const;
    /**
     * Deplace une entite
     * @param direction
     * @param ent
     * @return true si le deplacement c'est effectue
     */
    bool deplacement(int direction, entiteMouvante* ent);
    bool estVide(int x, int y) const;
    int getCase(int x, int y) const;


    int typeSelonDirection(int direction, position pJoueur);
    /**
     * Supprime du terrain l'entite en parametre
     * @param entite
     */
    void enleveEntiteTerrain(entite *entite);

    position getPositionDansDirection(position positionInit,int direction);

private:
    std::vector<std::vector<int>> d_terrain;

    void deplacement_DROITE(entiteMouvante* ent);
    void deplacement_GAUCHE(entiteMouvante* ent);
    void deplacement_HAUT(entiteMouvante* ent);
    void deplacement_BAS(entiteMouvante* ent);
    void deplacement_HAUT_GAUCHE(entiteMouvante* ent);
    void deplacement_HAUT_DROITE(entiteMouvante* ent);
    void deplacement_BAS_GAUCHE(entiteMouvante* ent);
    void deplacement_BAS_DROITE(entiteMouvante* ent);

};

#endif // TERRAIN_H
