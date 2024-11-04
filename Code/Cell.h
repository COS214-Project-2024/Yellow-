#ifndef GROUPPROJECT_CELL_H
#define GROUPPROJECT_CELL_H
#include <string>
using namespace std;
class Cell {
private:
    string type;
public:
    // Cell would possibly be the highest Abstraction of Buildings and Roads
    Cell(string cellType);  // for testing purposes
    string getCell();
    virtual ~Cell();
};


#endif //GROUPPROJECT_CELL_H
