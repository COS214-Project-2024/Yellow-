#ifndef GROUPPROJECT_CELL_H
#define GROUPPROJECT_CELL_H
#include <string>
#include <map>
#include "Coordinate.h"
#include <vector>
using namespace std;
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
    virtual Cell* clone() = 0;
};


#endif //GROUPPROJECT_CELL_H
