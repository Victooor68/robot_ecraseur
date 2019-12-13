#ifndef TERRAIN_H
#define TERRAIN_H

#include "entite.h"
#include <vector>
#include <iostream>

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
    terrain read(std::istream& is);
    bool estDansTerrain(entite ent, int direction) const;
    void seDeplaceADroiteSurTerrain(entite ent);
    void seDeplaceAGaucheSurTerrain(entite ent);
    void seDeplaceEnHautSurTerrain(entite ent);
    void seDeplaceEnBasSurTerrain(entite ent);

private:
    std::vector<std::vector<int>> d_terrain;
    int d_hauteur;
    int d_largeur;

};

#endif // TERRAIN_H
