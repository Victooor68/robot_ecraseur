#include <vector>
#include <iosfwd>
#include <iostream>
#include <entiteMouvante.h>
#include "terrain.h"
#include "../header/graphics.h"
#include "entite.h"
#include "robot.h"
#include "joueur.h"


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
    if (d_terrain.size() > 0 && d_terrain.at(0).size() > 0)
    {
        for(int k = 0; k < d_terrain.size()*2.6; k++)
        {
            os << "- ";
        }
        os << endl;
        for (int i = 0; i < d_terrain.size(); i++)
        {
            os << "| ";
            for (int j = 0; j < d_terrain[0].size(); j++)
            {
                switch(d_terrain.at(i).at(j))
                {
                    case VIDE : os<<"  "; break;
                    case DEBRIS : os<<"##"; break;
                    case JOUEUR_NORMAL : os<<"Jn"; break;
                    case JOUEUR_EXPERT : os<<"Je"; break;
                    case ROBOT_1GEN : os<<"R1"; break;
                    case ROBOT_2GEN : os<<"R2"; break;
                    default: break;
                }
                os << " | ";
            }
            os << endl;
            for(int k = 0; k < d_terrain.size()*2.6; k++)
            {
                os << "- ";
            }
            os << endl;
        }
    }
    else
        {
            os << "Erreur taille tableau";
        }
}

void terrain::afficheGraphique() const
{
    opengraphsize(750, 750);
    for (int i = 0; i < largeur(); i++) {
        for (int j = 0; j < hauteur(); j++) {
            int x1 = i * 750 / largeur();
            int x2 = 750 / largeur() + i * 750 / largeur();
            int y1 = j * 750 / hauteur();
            int y2 = 750 / hauteur() + j * 750 / hauteur();

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
                case ROBOT_2GEN:
                    setcolor(BLUE);
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
        case HAUT_DROITE :
            if(ent->getPosition().getPosY()+1 < largeur() && ent->getPosition().getPosX()-1 >= 0)
                estDansTerrain =true;
            break;
        case DROITE :
            if(ent->getPosition().getPosY()+1 < largeur())
                estDansTerrain = true;
            break;
        case BAS_DROITE :
            if(ent->getPosition().getPosY()+1 < largeur() && ent->getPosition().getPosX()+1 < hauteur())
                estDansTerrain =true;
            break;
        case HAUT :
            if(ent->getPosition().getPosX()-1 >= 0)
                estDansTerrain =true;
            break;
        case BAS :
            if(ent->getPosition().getPosX()+1 <hauteur())
                estDansTerrain =true;
            break;
        case HAUT_GAUCHE :
            if(ent->getPosition().getPosY()-1 >= 0 && ent->getPosition().getPosX()-1 >= 0)
                estDansTerrain =true;
            break;
        case GAUCHE :
            if(ent->getPosition().getPosY()-1 >=0)
                estDansTerrain = true;
            break;
        case BAS_GAUCHE :
            if(ent->getPosition().getPosY()-1 >=0 && ent->getPosition().getPosX()+1 < hauteur())
                estDansTerrain = true;
            break;
    }
    return estDansTerrain;
}

bool terrain::deplacement(int direction, entiteMouvante *ent) {
    switch(direction) {
        case BAS :
            deplacement_DROITE(ent);
            return true;
        case HAUT :
            deplacement_GAUCHE(ent);
            return true;
        case GAUCHE :
            deplacement_HAUT(ent);
            return true;
        case DROITE :
            deplacement_BAS(ent);
            return true;
        case HAUT_GAUCHE :
            deplacement_HAUT_GAUCHE(ent);
            return true;
        case BAS_GAUCHE :
            deplacement_HAUT_DROITE(ent);
            return true;
        case HAUT_DROITE :
            deplacement_BAS_GAUCHE(ent);
            return true;
        case BAS_DROITE :
            deplacement_BAS_DROITE(ent);
            return true;
        default:
            return false;
    }
}


void terrain::deplacement_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS(entiteMouvante *ent) {
    if(estDansTerrain(ent, DROITE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBas();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT(entiteMouvante *ent) {
    if(estDansTerrain(ent, GAUCHE)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHaut();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT_GAUCHE && ent->getType()!=JOUEUR_EXPERT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHautAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_HAUT_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS_GAUCHE && ent->getType() != JOUEUR_EXPERT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnHautADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS_GAUCHE(entiteMouvante *ent) {
    if(estDansTerrain(ent, HAUT_DROITE && ent->getType() != JOUEUR_EXPERT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBasAGauche();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

void terrain::deplacement_BAS_DROITE(entiteMouvante *ent) {
    if(estDansTerrain(ent, BAS_DROITE && ent->getType()!=JOUEUR_EXPERT)) {
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = VIDE;
        ent->seDeplaceEnBasADroite();
        d_terrain.at(ent->getPosition().getPosX()).at(ent->getPosition().getPosY()) = ent->getType();
    }
}

bool terrain::estVide(int x, int y) const {
    return d_terrain.at(x).at(y) == VIDE;
}

void terrain::setTerrain(const std::vector<std::vector<int>> terrain) {
    d_terrain = terrain;
}

void terrain::ajoutDansTerrain(const entite& ent) {
    d_terrain.at(ent.getPosition().getPosX()).at(ent.getPosition().getPosY()) = ent.getType();
}

int terrain::getCase(int x, int y)const
{
    return d_terrain.at(x).at(y);
}

int terrain::typeSelonDirection(int direction, position pos) {
    int typeCaseDansDirection=VIDE;
    if (pos.getPosX()+1>=this->largeur()||pos.getPosX()-1<0||pos.getPosY()+1>=this->hauteur()||pos.getPosY()-1<0){
        return typeCaseDansDirection;
    }
    switch (direction){
        case HAUT_DROITE :
            typeCaseDansDirection=this->getCase(pos.getPosX()-1,pos.getPosY()+1);
            break;
        case DROITE :
            typeCaseDansDirection=this->getCase(pos.getPosX(),pos.getPosY()+1);
            break;
        case BAS_DROITE :
            typeCaseDansDirection=this->getCase(pos.getPosX()+1,pos.getPosY()+1);
            break;
        case HAUT :
            typeCaseDansDirection=this->getCase(pos.getPosX()-1,pos.getPosY());
            break;
        case BAS :
            typeCaseDansDirection=this->getCase(pos.getPosX()+1,pos.getPosY());
            break;
        case HAUT_GAUCHE :
            typeCaseDansDirection=this->getCase(pos.getPosX()-1,pos.getPosY()-1);
            break;
        case GAUCHE :
            typeCaseDansDirection=this->getCase(pos.getPosX(),pos.getPosY()-1);
            break;
        case BAS_GAUCHE :
            typeCaseDansDirection=this->getCase(pos.getPosX()+1,pos.getPosY()-1);
            break;
    }
    return typeCaseDansDirection;
}

void terrain::enleveEntiteTerrain(entite *entite) {
    d_terrain.at(entite->getPosition().getPosX()).at(entite->getPosition().getPosY())=VIDE;
}

position terrain::getPositionDansDirection(position positionInit, int direction) {
    position positionApresDeplacement=positionInit;

    switch (direction){
        case HAUT_DROITE :
            positionApresDeplacement.seDeplaceDe(1,-1);
            break;
        case DROITE :
            positionApresDeplacement.seDeplaceDe(1,0);
            break;
        case BAS_DROITE :
            positionApresDeplacement.seDeplaceDe(1,1);
            break;
        case HAUT :
            positionApresDeplacement.seDeplaceDe(0,-1);
            break;
        case BAS :
            positionApresDeplacement.seDeplaceDe(0,1);
            break;
        case HAUT_GAUCHE :
            positionApresDeplacement.seDeplaceDe(-1,-1);
            break;
        case GAUCHE :
            positionApresDeplacement.seDeplaceDe(-1,0);
            break;
        case BAS_GAUCHE :
            positionApresDeplacement.seDeplaceDe(-1,1);
            break;
    }
    return positionApresDeplacement;
}
