//
//  position.hpp
//  robot_ecraseur
//
//  Created by Yassine Goeller on 11/11/2019.
//  Copyright © 2019 Yassine Goeller. All rights reserved.
//

#ifndef position_hpp
#define position_hpp

#include <stdio.h>
class position{
public:
    position();
    position(int x, int y);
    int getPosX() const;
    int getPosY() const;
    void seDeplaceEn(int x, int y);
    void seDeplace(int x, int y);
private:
    int d_x;
    int d_y;

};
#endif /* position_hpp */
