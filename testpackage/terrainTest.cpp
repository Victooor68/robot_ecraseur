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

        terrain ter{hauteur, largeur, listEntite};

        REQUIRE_EQ(ter.getEntite(0).position().getPosX(), e1.position().getPosX());
        REQUIRE_EQ(ter.getEntite(0).position().getPosY(), e1.position().getPosY());
    }
}