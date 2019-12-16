//
// Created by totoo on 09/11/2019.
//

#ifndef ROBOT_ECRASEUR_ENTITE_H
#define ROBOT_ECRASEUR_ENTITE_H

#include"position.hpp"

#define VIDE 0;
#define DEBRIS 1;
#define JOUEUR_NORMAL 8;
#define JOUEUR_EXPERT 9;
#define ROBOT_1GEN 3;
#define ROBOT_2GEN 4;

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
