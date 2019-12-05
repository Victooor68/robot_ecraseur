//
// Created by totoo on 09/11/2019.
//

#include "../header/entite.h"

entite::entite(int x, int y) : d_pos{x,y}, d_type{-1}
{}

entite::entite(class position pos):d_pos{pos}, d_type{-1}
{}

position entite::position() const{
    return d_pos;
}

int entite::type() const {
    return d_type;
}

bool entite::positionEgale(const class entite & ent) const
{
    return d_pos.getPosX() == ent.d_pos.getPosX() && d_pos.getPosY() == ent.d_pos.getPosY();
}
entite::~entite() {}