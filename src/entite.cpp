//
// Created by totoo on 09/11/2019.
//

#include "entite.h"

entite::entite(int x, int y) : d_pos{x, y}, d_type{-1}
{}

entite::entite(const position &position) : d_pos{position}, d_type{-1}
{}

entite::~entite()
{}

position entite::getPosition() const
{
    return d_pos;
}

int entite::getType() const
{
    return d_type;
}



