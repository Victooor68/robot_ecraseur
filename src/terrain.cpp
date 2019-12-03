
#include <vector>
#include <cstdlib>
#include "../header/terrain.h"

using namespace std;

terrain::terrain() : d_hauteur{10}, d_largeur{10}, d_listEntite{}
{}

terrain::terrain(int hauteur, int largeur) : d_hauteur{hauteur}, d_largeur{largeur}, d_listEntite{}
{}

terrain::terrain(int hauteur, int largeur, vector<entite> listEntite) : d_hauteur{hauteur}, d_largeur{largeur}, d_listEntite{listEntite}
{}

terrain::~terrain()
{}
