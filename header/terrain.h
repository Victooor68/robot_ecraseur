#ifndef TERRAIN_H
#define TERRAIN_H

#include "entite.h"
#include <vector>
#include <iostream>

class terrain
{
    public:
        terrain(int hauteur, int largeur, std::vector<entite> listEntite);
        virtual ~terrain();

        std::vector<std::vector<int>> getTerrain() const;
        entite getEntite(int i) const;
        void affiche(std::ostream& os) const;
        terrain read(std::istream& is);
        bool estDansTerrain(entite ent, int direction) const;
        void seDeplaceADroiteSurTerrain(entite ent);
        void seDeplaceAGaucheSurTerrain(entite ent);
        void seDeplaceEnHautSurTerrain(entite ent);
        void seDeplaceEnBasSurTerrain(entite ent);

    private:
    std::vector<std::vector<int>> d_terrain;
    std::vector<entite> d_listEntite;
};

#endif // TERRAIN_H
