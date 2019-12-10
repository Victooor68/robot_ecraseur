#include "../header/entiteMouvante.h"

entiteMouvante::entiteMouvante(int x, int y): entite(x,y)
{}

entiteMouvante::entiteMouvante(class position position):entite(position)
        {}

void entiteMouvante::seDeplaceADroite() {
    this->position().seDeplaceDe(1,0);
}

void entiteMouvante::seDeplaceAGauche() {
    this->position().seDeplaceDe(-1,0);
}

void entiteMouvante::seDeplaceEnBas() {
    this->position().seDeplaceDe(0,-1);
}

void entiteMouvante::seDeplaceEnHaut() {
    this->position().seDeplaceDe(0,1);
}

void entiteMouvante::seDeplaceEnBasADroite() {
    this->position().seDeplaceDe(1,-1);
}

void entiteMouvante::seDeplaceEnBasAGauche() {
    this->position().seDeplaceDe(-1,-1);
}

void entiteMouvante::seDeplaceEnHautADroite() {
    this->position().seDeplaceDe(1,1);
}

void entiteMouvante::seDeplaceEnHautAGauche() {
    this->position().seDeplaceDe(1,-1);
}