#ifndef TERRAIN_H
#define TERRAIN_H

#include "entite.h"
#include "entiteMouvante.h"
#include <vector>
#include <iostream>

#define BAS_GAUCHE 1
#define BAS_DEPLACEMENT 2
#define BAS_DROITE 3
#define GAUCHE_DEPLACEMENT 4
#define DROITE_DEPLACEMENT 6
#define HAUT_GAUCHE 7
#define HAUT_DEPLACEMENT 8
#define HAUT_DROITE 9


class terrain
{
public:
    terrain(int largeur, int hauteur);
    terrain( std::vector<std::vector<int>> terrain);
    virtual ~terrain();
    void setDTerrain(const std::vector<std::vector<int>> terrain);
    void ajoutDansTerrain(const entite& ent);
    std::vector<std::vector<int>> getTerrain() const;
    void affiche(std::ostream& os) const;
    void afficheGraphique() const;
    int largeur() const;
    int hauteur() const;
    bool estDansTerrain(entiteMouvante* ent, int direction) const;
    void deplacement(int direction, entiteMouvante* ent);
    bool estVide(int x, int y) const;
    int getCase(int x, int y) const;

private:
    std::vector<std::vector<int>> d_terrain;

private:

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
