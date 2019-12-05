//
// Created by Yassine Goeller on 05/12/2019.
//
#include "doctest.h"
#include "position.hpp"

TEST_CASE("Test des creations de position") {
    SUBCASE("Creation d'une position null") {
        position pos{};
        REQUIRE_EQ(pos.getPosX(), 0);
        REQUIRE_EQ(pos.getPosY(), 0);
    }
    SUBCASE("Creation d'une position") {
        int x = 32, y = 2;
        position pos{x, y};
        REQUIRE_EQ(pos.getPosX(), x);
        REQUIRE_EQ(pos.getPosY(), y);
    }
}

TEST_CASE("Test de deplacement") {
    int x = 32, y = 2, x2 = 2, y2 = 3;
    position pos{x, y};
    SUBCASE("Changement de positon sur une autre position") {
        pos.seDeplaceEn(x2, y2);
        REQUIRE_EQ(pos.getPosX(), x2);
        REQUIRE_EQ(pos.getPosY(), y2);
    }
    SUBCASE("Deplacement vectoriel d'une positon") {
        pos.seDeplaceDe(x2, y2);
        REQUIRE_EQ(pos.getPosX(), x+x2);
        REQUIRE_EQ(pos.getPosY(), y+y2);
    }
}

TEST_CASE("Test sur l'egaliter") {
    int x = 2, y = 2, x2 = 2, y2 = 2;
    position pos{x, y}, pos2{x2, y2};
    bool A = pos == pos2, B = pos.getPosX() == pos2.getPosX() && pos.getPosY() == pos2.getPosY();
    REQUIRE_EQ(A, B);
}