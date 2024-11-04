/**
 * @file Cell.h
 * @author Stefan and Johan Jansen van Rensburg
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef GROUPPROJECT_CELL_H
#define GROUPPROJECT_CELL_H
#include <string>
#include <map>
#include "Coordinate.h"
#include <vector>
using namespace std;
class Citizen;
class Cell {
protected:
    string type;
    vector<Coordinate> coordinates = vector<Coordinate>();//range of spots on map this object occupies
    char icon;
public:
    // Cell would possibly be the highest Abstraction of Buildings and Roads
    Cell(string cellType);  // for testing purposes
    string getCellType();
    Cell* getCell();
    vector<Coordinate> getCoordinates();
    void setCoordinates(vector<Coordinate> newCoordinates);
    virtual void setIcon() = 0;
    void setCellType(string str);
    virtual ~Cell();
    virtual void addCitizenToBuilding(Citizen* newCitizen);
    virtual Cell* clone() = 0;
    virtual void setProductionRate(int newRate);
    virtual void createBuildingResource() = 0;
    virtual void taxBuilding();
    virtual float getMoney() = 0;
    virtual void setMoney(float newAmount) = 0;
};


#endif //GROUPPROJECT_CELL_H
