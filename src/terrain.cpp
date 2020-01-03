#include <vector>
#include <iosfwd>
#include <iostream>
#include <entiteMouvante.h>
#include "terrain.h"
#include "../header/graphics.h"


using namespace std;

terrain::terrain(int largeur,int hauteur)
{
    for(int i=0; i<largeur; i++)
    {
        d_terrain.push_back(std::vector<int>());
        for(int j=0; j<hauteur; j++)
        {
            int valeurCase = VIDE;
            d_terrain.at(i).push_back(valeurCase);
        }
    }
}

terrain::~terrain()
{}

int terrain::hauteur() const
{
    return d_terrain.at(0).size();
}

int terrain::largeur() const
{
    return d_terrain.size();
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

            switch(d_terrain[i][j]){
                case VIDE :
                    setcolor(BLACK);
                    break;
                case JOUEUR_NORMAL:
                    setcolor(WHITE);
                    break;
                case ROBOT_1GEN:
                    setcolor(RED);
                    break;
                case DEBRIS:
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

bool terrain::estDansTerrain(entiteMouvante* ent, int direction) const {
    bool estDansTerrain = false;
    switch(direction){
        case BAS_GAUCHE :
            if(ent->getPosition().getPosX()+1 <= largeur() && ent->getPosition().getPosY()-1 >= 0)
                estDansTerrain =true;
            break;
        case BAS :
            if(ent->getPosition().getPosX()+1 <= largeur())
                estDansTerrain = true;
            break;
        case BAS_DROITE :
            if(ent->getPosition().getPosX()+1 <= largeur() && ent->getPosition().getPosY()+1 <= hauteur())
                estDansTerrain =true;
            break;
        case GAUCHE :
            if(ent->getPosition().getPosY()-1 >= 0)
                estDansTerrain =true;
            break;
        case DROITE :
            if(ent->getPosition().getPosY()+1 < hauteur())
                estDansTerrain =true;
            break;
        case HAUT_GAUCHE :
            if(ent->getPosition().getPosX()-1 >= 0 && ent->getPosition().getPosY()-1 >= 0)
                estDansTerrain =true;
            break;
        case HAUT :
            if(ent->getPosition().getPosX()-1 >=0)
                estDansTerrain =true;
            break;
        case HAUT_DROITE :
            if(ent->getPosition().getPosX()-1 >=0 && ent->getPosition().getPosY()+1 <= hauteur())
                estDansTerrain =true;
            break;
    }
    return estDansTerrain;
}

void terrain::deplacement(int direction, entiteMouvante *ent) {
    switch(direction) {
        case DROITE : deplacement_DROITE(ent); break;
        case GAUCHE : deplacement_GAUCHE(ent); break;
        case HAUT : deplacement_HAUT(ent); break;
        case BAS : deplacement_BAS(ent); break;
        case HAUT_GAUCHE : deplacement_HAUT_GAUCHE(ent); break;
        case HAUT_DROITE : deplacement_HAUT_DROITE(ent); break;
        case BAS_GAUCHE : deplacement_BAS_GAUCHE(ent); break;
        case BAS_DROITE : deplacement_BAS_DROITE(ent); break;
    }
}


void terrain::deplacement_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, DROITE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, GAUCHE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBas();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHaut();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT_GAUCHE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHautAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT_DROITE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHautADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS_GAUCHE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBasAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS_DROITE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBasADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

bool terrain::estVide(int x, int y) const {
    return d_terrain.at(x).at(y) == VIDE;
}

void terrain::setDTerrain(const std::vector<std::vector<int>> terrain) {
    d_terrain = terrain;
}

void terrain::ajoutDansTerrain(const entite& ent) {
    d_terrain.at(ent.getPosition().getPosX()).at(ent.getPosition().getPosY()) = ent.getType();
}

int terrain::getCase(int x, int y)const
{
    return d_terrain.at(x).at(y);
}