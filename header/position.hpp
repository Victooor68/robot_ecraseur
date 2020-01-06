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
    /**
     * Creer une position a partir de x et y
     * @param x
     * @param y
     */
    position(int x, int y);
    /**
     * Renvoie la valeur de x
     * @return x
     */
    int getPosX() const;
    /**
     * Renvoie la valeur de y
     * @return y
     */
    int getPosY() const;
    /**
     * Change la position en x et y
     */
    void seDeplaceEn(int x, int y);
    /**
     * Decale la position de x et y
     * @param x
     * @param y
     */
    void seDeplaceDe(int x, int y);
    bool operator==(const position& pos) const;

private:
    int d_x;
    int d_y;
};

#endif /* position_hpp */
