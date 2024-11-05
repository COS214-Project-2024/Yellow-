/**
* @class Map
* @brief A class that creates a map of the city
* @ingroup Composite
* @implements Section
*
* The Map class is a composite participant of the Composite design pattern. It is used to represent a map of the city.
*/
#include "Map.h"
#include "OpenField.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_set>

Map::Map(vector<vector<Cell*>> map, vector<vector<int>> distanceMatrix, vector<Cell*> pos)
        : map(map), distanceMatrix(distanceMatrix) {}

Map::Map(){
    map = vector<vector<Cell*>>();
    distanceMatrix = vector<vector<int>>();

    int rows = 10;
    int cols = 20;

    map.resize(rows, vector<Cell*>(cols, nullptr));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            map[i][j] = new OpenField();
        }
    }
}

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

vector<string> renderBuilding(const string& name, int widthCells, int heightCells) {
    int cellWidth = 9;
    int cellHeight = 3;

    int totalWidth = (widthCells * cellWidth) + widthCells - 1;
    int totalHeight = (heightCells * cellHeight);

    // cout << name << ": total height = " << totalHeight << endl << endl;


    vector<string> result(totalHeight, string(totalWidth, ' '));

    result[0] = string(totalWidth, '-');
    result[totalHeight - 1] = string(totalWidth, '-');

    if (totalHeight > 3) {
        for (int i = 1; i < totalHeight - 1; ++i) {
            result[i] = string(totalWidth, ' ');
            result[i][0] = '|';
            result[i][totalWidth - 1] = '|';
        }
    }
    else {
        result[1] = string(totalWidth, ' ');
        result[1][0] = '|';
        result[1][totalWidth - 1] = '|';
    }

    string abbreviation;
    if (name == "Townhall") {
        abbreviation = "TH";
    } else if (name == "WasteManagement") {
        abbreviation = "WM";
    } else if (name == "TrainStation") {
        abbreviation = "TS";
    } else if (name == "SteelFactory") {
        abbreviation = "SF";
    } else if (name == "PowerPlant") {
        abbreviation = "PP";
    } else if (name == "Police") {
        abbreviation = "PS";
    } else if (name == "Airport") {
        abbreviation = "Air";
    } else {
        // abbreviation = string(1, name[0]);
        abbreviation = name[0];
    }

    int textRow = totalHeight / 2;
    int textCol = (totalWidth - abbreviation.size()) / 2;
    if (abbreviation.size() == 1) {
        textCol = totalWidth / 2;
    }
    for (int i = 0; i < abbreviation.size(); ++i) {
        result[textRow][textCol + i] = abbreviation[i];
    }

    return result;
}

vector<string> renderField() {
    vector<string> result;
    result.push_back("---------");
    result.push_back("-       -");
    result.push_back("---------");
    return result;
}

vector<string> renderRoad() {
    vector<std::string> result;
    result.push_back("         ");
    result.push_back("         ");
    result.push_back("         ");
    return result;
}

bool isTopLeftCellOfBuilding(const vector<vector<Cell*>>& map, int row, int col) {
    if (!map[row][col]) return false;
    return (row == 0 || map[row - 1][col] != map[row][col]) &&
           (col == 0 || map[row][col - 1] != map[row][col]);
}

pair<int, int> getBuildingDimensions(const vector<vector<Cell*>>& map, int row, int col) {
    int width = 0, height = 0;

    while (col + width < map[row].size() && map[row][col + width] == map[row][col]) {
        width++;
    }

    while (row + height < map.size() && map[row + height][col] == map[row][col]) {
        height++;
    }

    return {width, height};
}

void displayMap(const vector<vector<Cell*>>& map) {
     std::unordered_set<Cell*> renderedCells;

    for (int row = 0; row < map.size(); ++row) {
        int maxLines = 0;
        vector<vector<string>> cellRenders;
        vector<int> cellWidths;

        for (int col = 0; col < map[row].size(); ++col) {
            Cell* cell = map[row][col];
            if (!cell) {
                cellRenders.push_back(renderField());
                cellWidths.push_back(renderField()[0].size());
                continue;
            }

            if (renderedCells.find(cell) != renderedCells.end()) {
                cellRenders.push_back(renderField());
                cellWidths.push_back(renderField()[0].size());
                continue;
            }

            if (isTopLeftCellOfBuilding(map, row, col)) {
                auto [widthCells, heightCells] = getBuildingDimensions(map, row, col);

                for (int i = 0; i < heightCells; ++i) {
                    for (int j = 0; j < widthCells; ++j) {
                        renderedCells.insert(map[row + i][col + j]);
                    }
                }

                string cellType = cell->getCellType();
                vector<string> cellLines = (cellType == "Road") ? renderRoad() : (cellType == "Field") ? renderField() : renderBuilding(cellType, widthCells, heightCells);

                maxLines = max(maxLines, static_cast<int>(cellLines.size()));
                cellRenders.push_back(cellLines);
                cellWidths.push_back(cellLines[0].size());
            } else {
                cellRenders.push_back(renderField());
                cellWidths.push_back(renderField()[0].size());
            }
        }

        for (int lineIndex = 0; lineIndex < maxLines; ++lineIndex) {
            for (size_t i = 0; i < cellRenders.size(); ++i) {
                const auto& cellLines = cellRenders[i];
                cout << (lineIndex < cellLines.size() ? cellLines[lineIndex] : string(cellWidths[i], ' ')) << " ";
            }
            cout << "\n";
        }
    }
}

void Map::printMap() {

    displayMap(map);

}

void Map::addNode(Cell *object) {
    int x = 0;
    int y = 0;
    vector<Coordinate> coordinates = object->getCoordinates();
    if (coordinates.empty()){
        return;
    }
    for (int K = 0; K < coordinates.size(); K++){
        x = coordinates[K].x;
        y = coordinates[K].y;
        if ((x < map.size()) && (y < map[x].size())){
            map[x][y] = object;
        }
    }
}

void Map::addNode(Cell *object, vector<Coordinate> coordinates){
    object->setCoordinates(std::move(coordinates));
    addNode(object);
}

void Map::removeNode(Cell *object) {
//Todo: remove object from all coords that object occupies
}

void Map::removeNode(Coordinate *coordinate) {
//Todo: remove object based on coords
}

void Map::addToMatrix(Cell* object) {
    if (distanceMatrix.empty()) {
        distanceMatrix.resize(1, std::vector<int>(1, 0));
    } else {
        int newSize = distanceMatrix.size() + 1;
        distanceMatrix.resize(newSize);
        for (auto& row : distanceMatrix) {
            row.resize(newSize, 0);
        }
    }
    pos.resize(pos.size()+1, 0);

}

void Map::djikstrasAneurysm(Cell* object){
    if (object->getCellType() == "Road"){
        return;
    }
    vector<Cell*> borderRoads = findBorderRoads(object);

}

vector<Cell*> Map::findBorderRoads(Cell* building) {
    vector<Cell*> borderRoads;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < this->map.size(); i++) {
        for (int j = 0; j < this->map[i].size(); j++) {
            if (map[i][j]->getCellType() != "Road") {
                for (auto& dir : directions) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];
                    if (isInBounds(newRow, newCol) && map[newRow][newCol]->getCellType() == "Road") {
                        borderRoads.push_back(map[newRow][newCol]);
                    }
                }
            }
        }
    }
    return borderRoads;
}

bool Map::isInBounds(int r, int c) {
    return r >= 0 && r < map.size() && c >= 0 && c < map[0].size();
}

void Map::removeFromMatrix(Cell *object) {

}

int Map::retrieveDistance(Cell *res, Cell *job) {
    int resIndex = findIndex(res);
    int jobIndex = findIndex(job);
    if (resIndex >= 0 && resIndex < distanceMatrix.size() &&
        jobIndex >= 0 && jobIndex < distanceMatrix[resIndex].size()) {
        int result = distanceMatrix[resIndex][jobIndex];
        return result;
    } else {
        return -1;
    }
}

int Map::findIndex(Cell *object) {
    for (int K = 0; K < pos.size(); ++K){
        if (pos[K] == object){
            return K;
        }
    }

    return -1;
}

vector<Coordinate> Map::returnFreeCoords() {
    vector<Coordinate> freeCoords;
    vector<Coordinate> cellCoords;
    for (int K = 0; K < map.size(); ++K) {
        for (int i = 0; i < map[K].size(); ++i) {
            if (map[K][i]->getCellType() == "Field") {
                cellCoords = map[K][i]->getCoordinates();
                for (int j = 0; j < cellCoords.size(); ++j){
                    freeCoords.push_back(cellCoords[j]);
                }
            }
        }
    }
    return freeCoords;
}

Map::Map(const Map &other) {
    map.resize(other.map.size());
    for (size_t i = 0; i < other.map.size(); ++i) {
        map[i].resize(other.map[i].size());
        for (size_t j = 0; j < other.map[i].size(); ++j) {
            map[i][j] = other.map[i][j]->clone();
        }
    }

    distanceMatrix = other.distanceMatrix;
    pos.resize(other.pos.size());
    for (size_t i = 0; i < other.pos.size(); ++i) {
        pos[i] = other.pos[i]->clone();
    }

    buildings.resize(other.buildings.size());
    for (size_t i = 0; i < other.buildings.size(); ++i) {
        buildings[i] = other.buildings[i]->clone();
    }

    setRoadConnections();
}

void Map::setRoadConnections() {
    vector<Cell*> roadCoords;
    Road* road;
    for (int K = 0; K < buildings.size(); ++K){
        roadCoords = findBorderRoads(buildings[K]);
        for (int i = 0; i < roadCoords.size(); ++i){
            road = (Road*) findObject(roadCoords[i]->getCoordinates()[0]);
            if (road->contains(buildings[K])){
                continue;
            }else{
                road->addBuilding(buildings[K]);
            }
        }
    }
}

Cell *Map::findObject(Coordinate coord) {
    return map[coord.x][coord.y];
}

vector<vector<Cell *>> Map::getMap() {
    return map;
}
