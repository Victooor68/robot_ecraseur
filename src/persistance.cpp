//
// Created by totoo on 03/12/2019.
//

#include <iostream>
#include <fstream>
#include "../header/persistance.h"

char delimiterChar = '|', endChar='$';

void  persistance::sauve(std::ofstream &f, terrain t) {

    for (int i = 0; i <t.getTerrain().size() ; ++i) {
        for (int j = 0; j <t.getTerrain().at(i).size() ; ++j) {
            f<<t.getTerrain().at(i).at(j);
        }
        f << delimiterChar;
    }
    f<<endChar;
}



terrain persistance::restore(std::ifstream &is) {
    int ASCIInteger = 48;
    std::string terrainRecupere;
    getline(is, terrainRecupere);
    std::vector<std::vector<int>> firstDimensionVector;
    std::vector<int> secondDimensionVector;
    int index=0;
    while (terrainRecupere.at(index) != endChar)
    {
        if (terrainRecupere.at(index) == delimiterChar){
            firstDimensionVector.push_back(secondDimensionVector);
            secondDimensionVector.clear();
        } else{
            secondDimensionVector.push_back(terrainRecupere.at(index) - ASCIInteger);
        }
        ++index;
    }
    terrain restoredTerrain {firstDimensionVector};
    return restoredTerrain;
}