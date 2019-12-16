#ifndef TERRAIN_H
#define TERRAIN_H

#include "entite.h"
#include <vector>
#include <iostream>

#define BAS_GAUCHE 1
#define BAS 2
#define BAS_DROITE 3
#define GAUCHE 4
#define DROITE 6
#define HAUT_GAUCHE 7
#define HAUT 8
#define HAUT_DROITE 9


class terrain
{
    public:
        terrain(int largeur, int hauteur);
        terrain( std::vector<std::vector<int>> terrain);
    virtual ~terrain();

    std::vector<std::vector<int>> getTerrain() const;
    void affiche(std::ostream& os) const;
    void afficheGraphique() const;
    int largeur() const;
    int hauteur() const;
    bool estDansTerrain(entiteMouvante* ent, int direction) const;
    void seDeplaceADroiteSurTerrain(entiteMouvante* ent);
    void seDeplaceAGaucheSurTerrain(entiteMouvante* ent);
    void seDeplaceEnHautSurTerrain(entiteMouvante* ent);
    void seDeplaceEnBasSurTerrain(entiteMouvante* ent);

private:
    std::vector<std::vector<int>> d_terrain;
};

#endif // TERRAIN_H
