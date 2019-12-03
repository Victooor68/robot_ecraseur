#include "../header/doctest.h"
#include "../header/entite.h"


void lesCoordonnesDuPointSontExactement(const entite& e,int x,int y) {
    position p = e.position();
            REQUIRE( p.getPosX() == x );
            REQUIRE( p.getPosY() == y );
}

TEST_CASE("Test constructeur entite"){
    int x = 3, y=4;
    SUBCASE("Le constructeur avec des coordonnées est correct" ) {

        entite e1 {x,y};
        lesCoordonnesDuPointSontExactement(e1, x, y);
    }
    SUBCASE("Le constructeur avec position est correct" ) {
        position p {x,y};
        entite e2 {p};
        lesCoordonnesDuPointSontExactement(e2, x, y);
    }
}

