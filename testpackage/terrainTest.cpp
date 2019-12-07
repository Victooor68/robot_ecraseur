//
// Created by totoo on 03/12/2019.
//
#include "../header/doctest.h"
#include "../header/terrain.h"
#include "../header/entite.h"

TEST_CASE("Test constructeur terrain")
{
    SUBCASE("Test taille terrain") {
        int hauteur = 10;
        int largeur = 10;

        terrain ter{hauteur, largeur};

        REQUIRE_EQ(hauteur, ter.getTerrain().size());
        REQUIRE_EQ(largeur, ter.getTerrain().at(0).size());
    }
}