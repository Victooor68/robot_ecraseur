#include "doctest.h"
#include "robot_2gen.h"
#include "joueur.h"
#include "terrain.h"

TEST_CASE("Test de la classe robot_2gen")
{
    SUBCASE("methode deplacement_Auto")
    {
        SUBCASE("avec joueur plus bas que le robot")
        {
            robot_2gen robot{3,3};
            joueur j{3, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, BAS);
        }
        SUBCASE("avec joueur plus haut que le robot")
        {
            robot_2gen robot{3,6};
            joueur j{3, 3, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, HAUT);
        }
        SUBCASE("avec joueur plus à gauche du robot")
        {
            robot_2gen robot{3,6};
            joueur j{1, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, GAUCHE);
        }
        SUBCASE("avec joueur plus à droite du robot")
        {
            robot_2gen robot{3,3};
            joueur j{5, 3, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, DROITE);
        }
        SUBCASE("avec joueur plus à droite et plus haut du robot")
        {
            robot_2gen robot{3,3};
            joueur j{5, 1, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, HAUT_DROITE);
        }
        SUBCASE("avec joueur plus à gauche et plus haut du robot")
        {
            robot_2gen robot{3,3};
            joueur j{1, 1, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, HAUT_GAUCHE);
        }
        SUBCASE("avec joueur plus à droite et plus bas du robot")
        {
            robot_2gen robot{3,3};
            joueur j{5, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, BAS_DROITE);
        }
        SUBCASE("avec joueur plus à gauche et plus bas du robot")
        {
            robot_2gen robot{3,3};
            joueur j{1, 6, "test"};
            joueur* joueur = &j;

            int direction = robot.deplacement_Auto(joueur);

            REQUIRE_EQ(direction, BAS_GAUCHE);
        }
    }
}