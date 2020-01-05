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
    terrain(int largeur, int hauteur);
    terrain( std::vector<std::vector<int>> terrain);
    virtual ~terrain();
    void setTerrain(const std::vector<std::vector<int>> terrain);
    void ajoutDansTerrain(const entite& ent);
    std::vector<std::vector<int>> getTerrain() const;
    void affiche(std::ostream& os) const;
    void afficheGraphique() const;
    int largeur() const;
    int hauteur() const;
    bool estDansTerrain(entiteMouvante* ent, int direction) const;
    bool deplacement(int direction, entiteMouvante* ent);
    bool estVide(int x, int y) const;
    int getCase(int x, int y) const;


    int typeSelonDirection(int direction, position pJoueur);

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

    bool collisionRobot(robot* robot);
};

#endif // TERRAIN_H
