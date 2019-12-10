//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include"position.hpp"

const static int DEBRIS=1;
const static int JOUEURNORMAL=8;
const static int JOUEUREXPERT=9;
const static int ROBOT1GEN = 3;
const static int ROBOT2GEN = 4;

class entite {
public:
    //Constructor with 2 int
    entite(int x, int y);
    //Constructor with position
    entite(position position);
    //Destructor
    ~entite();
    //Accessor type
    int type()const ;
    //accessor position
    position position()const ;
    bool positionEgale(const entite& ent) const;

protected:
    class position d_pos;
    int d_type;
};


#endif //ROBOT_ECRASEUR_ENTITE_H
