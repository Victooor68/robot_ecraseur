#ifndef TERRAIN_H
#define TERRAIN_H


class terrain
{
    public:
        terrain();
        virtual ~terrain();

        int hauteur() const;
        int largeur() const;
        int getEntite(int i) const;
        void affiche(ostream& os) const;
        terrain read(istream& is);
        bool estDansTerrain(entite ent, int direction) const;
        void seDeplaceADroiteSurTerrain(entite ent);
        void seDeplaceAGaucheSurTerrain(entite ent);
        void seDeplaceEnHautSurTerrain(Entite ent);
        void seDeplaceEnBasSurTerrain(Entite ent);

    private:
    int d_hauteur;
    int d_largeur;
    entite[] listEntite;
};

#endif // TERRAIN_H
