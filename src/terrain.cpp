
#include <vector>
#include <iosfwd>
#include <iostream>
#include "../header/terrain.h"

using namespace std;

terrain::terrain(int hauteur,int largeur, vector<entite> listEntite) : d_listEntite{listEntite}, d_terrain{}
{
    vector<vector<int>> terrain;
    for(int i=0; i<hauteur; i++)
    {
        for(int j=0; j<largeur; j++)
        {
            terrain[i][j] = 0;
        }
    }
    for(auto entite : listEntite)
    {
        terrain[entite.position().getPosX()][entite.position().getPosY()] = entite.type();
    }

    d_terrain = terrain;
}

terrain::~terrain()
{}


entite terrain::getEntite(int i) const {
    if(i<d_listEntite.size()){
        return d_listEntite[i];
    }
}

void terrain::affiche(ostream &os) const {
    if (d_terrain.size() > 0 && d_terrain[0].size() > 0) {
        for (int i = 0; i < d_terrain.size(); i++) {
            for (int j = 0; j < d_terrain[0].size(); j++) {
                cout << d_terrain[i][j] + "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Erreur taille tableau";
    }
}