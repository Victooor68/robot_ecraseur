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
        terrain read(std::istream& is);
        bool estDansTerrain(entite ent, int direction) const;
        void seDeplaceADroiteSurTerrain(entite ent);
        void seDeplaceAGaucheSurTerrain(entite ent);
        void seDeplaceEnHautSurTerrain(entite ent);
        void seDeplaceEnBasSurTerrain(entite ent);
    std::vector<std::vector<int>> d_terrain;
    private:

};

#endif // TERRAIN_H
