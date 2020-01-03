//
// Created by leand on 10/12/2019.
//
#include "doctest.h"
#include "entiteMouvante.h"


static void lesCoordonnesDuPointSontExactement(const entiteMouvante& e,int x,int y) {
    position p = e.getPosition();
            REQUIRE( p.getPosX() == x );
            REQUIRE( p.getPosY() == y );
}

TEST_CASE("Test constructeur entiteMouvante"){
    int x = 3, y=4;
    SUBCASE("Le constructeur avec des coordonnées est correct" ) {

        entiteMouvante e1 {x,y};
        lesCoordonnesDuPointSontExactement(e1, x, y);
    }
    SUBCASE("Le constructeur avec position est correct" ) {
        position p {x,y};
        entiteMouvante e2 {p};
        lesCoordonnesDuPointSontExactement(e2, x, y);
    }
}

TEST_CASE("Test deplacement de l'entité mouvante"){
    int x=4, y=6;
    position pos {x,y};
    entiteMouvante e1 {x,y};
    SUBCASE("Test deplacement à Droite"){
        e1.seDeplaceADroite();
        lesCoordonnesDuPointSontExactement(e1,x+1,y);
    }
    SUBCASE("Test deplacement à Gauche"){
        e1.seDeplaceAGauche();
        lesCoordonnesDuPointSontExactement(e1,x-1,y);
    }
    SUBCASE("Test deplacement en Bas"){
        e1.seDeplaceEnBas();
        lesCoordonnesDuPointSontExactement(e1,x,y+1);
    }
    SUBCASE("Test deplacement en Haut"){
        e1.seDeplaceEnHaut();
        lesCoordonnesDuPointSontExactement(e1,x,y-1);
    }
    SUBCASE("Test deplacement en Haut à Droite"){
        e1.seDeplaceEnHautADroite();
        lesCoordonnesDuPointSontExactement(e1,x+1,y-1);
    }
    SUBCASE("Test deplacement en Haut à Gauche"){
        e1.seDeplaceEnHautAGauche();
        lesCoordonnesDuPointSontExactement(e1,x-1,y-1);
    }
    SUBCASE("Test deplacement en Bas à Droite"){
        e1.seDeplaceEnBasADroite();
        lesCoordonnesDuPointSontExactement(e1,x+1,y+1);
    }
    SUBCASE("Test deplacement en Bas à Gauche"){
        e1.seDeplaceEnBasAGauche();
        lesCoordonnesDuPointSontExactement(e1,x-1,y+1);
    }
}