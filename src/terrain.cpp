
#include <vector>
#include <iosfwd>
#include <iostream>
#include "terrain.h"
#include "../header/graphics.h"


using namespace std;

terrain::terrain(int largeur,int hauteur): d_largeur{largeur}, d_hauteur{hauteur}
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

int terrain::hauteur() const
{
    return d_hauteur;
}

int terrain::largeur() const
{
    return d_largeur;
}


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

void terrain::afficheGraphique() const
{
    opengraphsize(750, 750);
    for (int i = 0; i < largeur(); i++) {
        for (int j = 0; j < hauteur(); j++) {
            int x1 = i * 750 / largeur();
            int x2 = x1 + 750 / largeur();
            int y1 = j * 750 / hauteur();
            int y2 = y2 + 750 / hauteur();

            switch (d_terrain[i][j]){
                case 0 : //case vide
                    setcolor(BLACK);
                    break;
                case 1: //joueur
                    setcolor(WHITE);
                    break;
                case 2: //robot
                    setcolor(RED);
                    break;
                case 3: //debrit
                    setcolor(YELLOW);
                    break;
                default: //erreur
                    setcolor(GREEN);
                    break;
            }
            bar(x1,y1,x2,y2);
        }
    }
    getch();
    closegraph();
}

std::vector<std::vector<int>> terrain::getTerrain() const {
    return d_terrain;
}
terrain::terrain(std::vector<std::vector<int>> terrain):d_terrain(terrain)
{}