
#include <vector>
#include <iosfwd>
#include "../header/terrain.h"

using namespace std;

/**terrain::terrain(const int hauteur,const int largeur, vector<entite> listEntite) : d_listEntite{listEntite}
{
    int terrain[hauteur][largeur];
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

    d_terrain{terrain};
}

terrain::~terrain()
{}


entite terrain::getEntite(int i) const {
    if(i<d_listEntite.size()){
        return d_listEntite[i];
    }
}

void terrain::affiche(ostream &os) const {
    for(int i=0; )
}*/