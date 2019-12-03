//
// Created by totoo on 03/12/2019.
//
#include "../header/doctest.h"
#include "../header/terrain.h"
#include "../header/entite.h"

TEST_CASE("Test constructeur terrain")
{
    SUBCASE("Test entite sauvegardé dans terrain") {
        int hauteur = 10;
        int largeur = 10;
        std::vector<entite> listEntite;

        entite e1{0, 0};
        listEntite.push_back(e1);

        /*
        entite e2{3, 8};
        entite e3{6, 9};
        entite e4{4, 3};
        entite e5{1, 6};
         */

        terrain ter{hauteur, largeur, listEntite};

        REQUIRE(ter.getEntite(0) == e1);
    }
}