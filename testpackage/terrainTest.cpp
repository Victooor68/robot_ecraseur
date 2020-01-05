//
// Created by totoo on 03/12/2019.
//
#include "doctest.h"
#include "terrain.h"
#include "entite.h"
#include "robot_1gen.h"

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
            entiteMouvante entM{5, 5};
            entiteMouvante* ent = &entM;

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
            entiteMouvante entM{0, 0};
            entiteMouvante* ent = &entM;
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 1));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 4));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 9));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 8));
            REQUIRE_EQ(false, ter.estDansTerrain(ent, 7));

            entiteMouvante entM2{largeur, hauteur};
            entiteMouvante* ent2 = &entM2;
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 1));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 2));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 6));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 3));
            REQUIRE_EQ(false, ter.estDansTerrain(ent2, 9));
        }
    }

    SUBCASE("Test methodes de deplacements") {
        entiteMouvante entM{5, 5};
        entiteMouvante* ent = &entM;
        SUBCASE("Deplacement a droite") {
            position pos{5,5};
            REQUIRE_EQ(pos, ent->getPosition());
            ent->seDeplaceADroite();
            position pos2{6, 5};
            REQUIRE_EQ(pos2, ent->getPosition());

        }
    }

    SUBCASE("Test méthode deplacement") {
        terrain ter2{8,8};

        entiteMouvante entM{5, 5};
        entiteMouvante* ent = &entM;

        position pos1{5,5};
        REQUIRE_EQ(pos1, ent->getPosition());

        position pos2{6, 5};
        ter2.deplacement(BAS, ent);
        REQUIRE_EQ(pos2, ent->getPosition());
    }

}

