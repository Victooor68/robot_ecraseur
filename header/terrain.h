#ifndef TERRAIN_H
#define TERRAIN_H


#include "entite.h"

class terrain
{
    public:
        terrain();
        terrain(int hauteur, int largeur);
        terrain(int hauteur, int largeur, vector<entite> listEntite);
        virtual ~terrain();

        int hauteur() const;
        int largeur() const;
        int getEntite(int i) const;
        void affiche(ostream& os) const;
        terrain read(istream& is);
        bool estDansTerrain(entite ent, int direction) const;
        void seDeplaceADroiteSurTerrain(entite ent);
        void seDeplaceAGaucheSurTerrain(entite ent);
        void seDeplaceEnHautSurTerrain(entite ent);
        void seDeplaceEnBasSurTerrain(entite ent);

    private:
    int d_hauteur;
    int d_largeur;
    vector<entite> d_listEntite;
};

#endif // TERRAIN_H
