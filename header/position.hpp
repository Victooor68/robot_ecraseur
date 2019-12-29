//
//  position.hpp
//  robot_ecraseur
//
//  Created by Yassine Goeller on 11/11/2019.
//  Copyright © 2019 Yassine Goeller. All rights reserved.
//

#ifndef position_hpp
#define position_hpp


class position {
public:
    position();
    position(int x, int y);
    int getPosX() const;
    int getPosY() const;
    void seDeplaceEn(int x, int y);
    void seDeplaceDe(int x, int y);
    bool operator==(const position& pos) const;

private:
    int d_x;
    int d_y;
};

#endif /* position_hpp */
