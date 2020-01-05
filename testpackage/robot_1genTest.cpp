#include "doctest.h"
#include "robot_1gen.h"
#include "joueur.h"
#include "terrain.h"

TEST_CASE("Test de la classe robot_1gen")
{
    SUBCASE("methode deplacement_Auto")
    {
        SUBCASE("avec joueur plus bas que le robot")
        {
            robot_1gen robot{3,3};
            joueur j{3, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, DROITE);
        }
        SUBCASE("avec joueur plus haut que le robot")
        {
            robot_1gen robot{3,6};
            joueur j{3, 3, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, GAUCHE);
        }
        SUBCASE("avec joueur plus à gauche du robot")
        {
            robot_1gen robot{3,6};
            joueur j{1, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, HAUT);
        }
        SUBCASE("avec joueur plus à droite du robot")
        {
            robot_1gen robot{3,3};
            joueur j{5, 3, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, BAS);
        }
    }
}


