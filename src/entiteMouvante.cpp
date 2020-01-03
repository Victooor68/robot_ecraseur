#include "../header/entiteMouvante.h"


entiteMouvante::entiteMouvante(int x, int y): entite(x,y)
{}

entiteMouvante::entiteMouvante(class position position):entite(position)
{}

void entiteMouvante::seDeplaceADroite() {
    this->d_pos.seDeplaceDe(1,0);
}

void entiteMouvante::seDeplaceAGauche() {
    this->d_pos.seDeplaceDe(-1,0);
}

void entiteMouvante::seDeplaceEnBas() {
    this->d_pos.seDeplaceDe(0,1);
}

void entiteMouvante::seDeplaceEnHaut() {
    this->d_pos.seDeplaceDe(0,-1);
}

void entiteMouvante::seDeplaceEnBasADroite() {
    this->d_pos.seDeplaceDe(1,1);
}

void entiteMouvante::seDeplaceEnBasAGauche() {
    this->d_pos.seDeplaceDe(-1,1);
}

void entiteMouvante::seDeplaceEnHautADroite() {
    this->d_pos.seDeplaceDe(1,-1);
}

void entiteMouvante::seDeplaceEnHautAGauche() {
    this->d_pos.seDeplaceDe(-1,-1);
}