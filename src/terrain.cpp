
#include <vector>
#include <iosfwd>
#include <iostream>
#include "../header/terrain.h"

using namespace std;

terrain::terrain(int largeur,int hauteur)
{
    for(int i=0; i<largeur; i++)
    {
        d_terrain.push_back(std::vector<int>());
        for(int j=0; j<hauteur; j++)
        {
            d_terrain.at(i).push_back(0);
        }
    }
}

terrain::~terrain()
{}


void terrain::affiche(ostream &os) const {
    if (d_terrain.size() > 0 && d_terrain.at(0).size() > 0) {
        for (int i = 0; i < d_terrain.size(); i++) {
            for (int j = 0; j < d_terrain[0].size(); j++) {
                cout << d_terrain.at(i).at(j) << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "Erreur taille tableau";
    }
}

std::vector<std::vector<int>> terrain::getTerrain() const {
    return d_terrain;
}