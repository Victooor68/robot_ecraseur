//
// Created by totoo on 09/11/2019.
//

#include "../header/entite.h"

entite::entite(int x, int y) : d_pos{x,y}, d_type{-1}
{}

entite::entite(position pos):d_pos{pos}, d_type{-1}
{}

position entite::Position() {
    return d_pos;
}

int entite::Type() {
    return d_type;
}
