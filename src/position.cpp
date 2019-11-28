//
//  position.cpp
//  robot_ecraseur
//
//  Created by Yassine Goeller on 11/11/2019.
//  Copyright © 2019 Yassine Goeller. All rights reserved.
//

#include "position.hpp"

position::position() : d_x{0}, d_y{0}{}
position::position(int x, int y) : d_x{x}, d_y{y}{}
int position::getPosX() const
{return d_x;}
int position::getPosY() const
{ return d_y;}
void position::seDeplaceEn(int x, int y)
{
    d_x = x;
    d_y = y;
}
