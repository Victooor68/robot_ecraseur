//
// Created by totoo on 03/12/2019.
//
#include "../header/doctest.h"
#include "../header/terrain.h"
#include "../header/entite.h"

TEST_CASE("Test terrain")
{
    int hauteur = 10;
    int largeur = 10;

    terrain ter{hauteur, largeur};

    SUBCASE("Test constructeur taille terrain") {
        REQUIRE_EQ(hauteur, ter.getTerrain().size());
        REQUIRE_EQ(largeur, ter.getTerrain().at(0).size());
    }
    SUBCASE("Test methodes hauteur et largeur") {
        REQUIRE_EQ(hauteur, ter.hauteur());
        REQUIRE_EQ(largeur, ter.largeur());
    }

    SUBCASE("Test methode estDansTerrain") {

        SUBCASE("Deplacements corrects") {
            entite ent{5, 5};

                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 1));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 2));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 3));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 4));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 6));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 7));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 8));
                    REQUIRE_EQ(true, ter.estDansTerrain(ent, 9));
        }
        SUBCASE("Deplacements incorrects") {
            entite ent{0, 0};
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 1));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 2));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 3));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 4));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 7));

            entite ent2{largeur, hauteur};
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 6));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 8));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 9));
        }
    }

}

