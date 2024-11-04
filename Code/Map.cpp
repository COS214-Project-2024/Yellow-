/**
* @class Map
* @brief A class that creates a map of the city
* @ingroup Composite
* @implements Section
*
* The Map class is a composite participant of the Composite design pattern. It is used to represent a map of the city.
*/
#include "Map.h"
Map::Map(vector<vector<Cell*>> map, vector<vector<Cell*>> distanceMatrix)
        : map(map), distanceMatrix(distanceMatrix) {}

void Map::addNode(Cell *object, int x, int y, int height, int width) {
    int curHeight = x;
    int curWidth = y;

    for (int i = 0; i < map.size(); i++) {
        if (i == x) {
            for (int j = 0; j < map[i].size(); j++) {
                if (j == y) {
                        for (int row = 0; row < height; row++) {
                            for (int col = 0; col < width; col++) {
                                if (row + curHeight < map.size() && col + curWidth < map[i].size()) {
                                    map[row + curHeight][col + curWidth] = object;
                                }

                                // curWidth++;
                            }

                            // curHeight++;
                        }
                }
            }
        }
    }


}

void Map::printMap() {
    for (int i = 0; i < map.size(); i++) {

        for (int j = 0; j < map[i].size(); j++) {
            cout << "|------------|\t";
        }

        cout << endl;

        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                cout << "| " << map[i][j]->getCell() << " |\t";
            }
            else {
                cout << "|            |\t";
            }
        }
        cout << endl;
        for (int j = 0; j < map[i].size(); j++) {
            cout << "|------------|\t";
        }
        cout << endl << endl;
    }
}
