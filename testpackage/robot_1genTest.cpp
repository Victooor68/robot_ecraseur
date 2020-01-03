#include "doctest.h"
#include "robot_1gen.h"
#include "joueur.h"
#include <iostream>

TEST_CASE("Test de la classe robot_1gen")
{
    SUBCASE("methode deplacement_Auto")
    {
        SUBCASE("avec joueur plus haut que le robot")
        {
            robot_1gen robot{3,3};
            joueur j{3, 6, "test"};

            joueur* joueur = &j;
            robot.deplacement_Auto(joueur);
            std::cout<<"Position : (x: "<<robot.getPosition().getPosX() <<", y: "<<robot.getPosition().getPosY();

            position pos{3, 2};
            REQUIRE_EQ(robot.getPosition(), pos);
        }
        SUBCASE("avec joueur plus bas que le robot")
        {
            robot_1gen robot{3,6};
            joueur j{3, 3, "test"};

            joueur* joueur = &j;
            robot.deplacement_Auto(joueur);

            position pos{3, 7};
            REQUIRE_EQ(robot.getPosition(), pos);
        }
        SUBCASE("avec joueur plus à gauche du robot")
        {
            robot_1gen robot{3,6};
            joueur j{1, 6, "test"};

            joueur* joueur = &j;
            robot.deplacement_Auto(joueur);

            position pos{2,6};
            REQUIRE_EQ(robot.getPosition(), pos);
        }
        SUBCASE("avec joueur plus à droite du robot")
        {
            robot_1gen robot{3,3};
            joueur j{5, 3, "test"};

            joueur* joueur = &j;
            robot.deplacement_Auto(joueur);

            position pos{4, 3};
            REQUIRE_EQ(robot.getPosition(), pos);
        }
    }
}


