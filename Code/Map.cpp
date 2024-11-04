//
// Created by sjvr0 on 2024/10/22.
//

#include "Map.h"
#include "OpenField.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

Map::Map(vector<vector<Cell*>> map, vector<vector<int>> distanceMatrix, vector<Cell*> pos)
        : map(map), distanceMatrix(distanceMatrix) {}

Map::Map(){
    map = vector<vector<Cell*>>();
    distanceMatrix = vector<vector<int>>();

    int rows = 20;
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

vector<string> handleColumns(const string& type, Cell *cell) {
    // Find min and max y values for height
    int minY = cell->getCoordinates()[0].y, maxY = cell->getCoordinates()[0].y;
    for (const auto& coord : cell->getCoordinates()) {
        minY = min(minY, coord.y);
        maxY = max(maxY, coord.y);
    }

    // Determine height (height = range + 4)
    int height = (minY == maxY) ? 1 : maxY - minY;
    height += 4;

    // Find min and max x values for width
    int minX = cell->getCoordinates()[0].x, maxX = cell->getCoordinates()[0].x;
    for (const auto& coord : cell->getCoordinates()) {
        minX = min(minX, coord.x);
        maxX = max(maxX, coord.x);
    }

    // Determine width (width = range + 4)
    int width = maxX - minX + 4;

    // Initialize string array with spaces
    vector<string> box(height, string(width, ' '));

    // Top and bottom border
    box[0] = string(width, '-');
    box[height - 1] = string(width, '-');

    // Left and right borders
    for (int i = 1; i < height - 1; ++i) {
        box[i][0] = '|';
        box[i][width - 1] = '|';
    }

    // Insert the type in the middle row
    int middleRow = height / 2;
    int typeStart = (width - type.length()) / 2;
    box[middleRow].replace(typeStart, type.length(), type);

    return box;
}


void Map::printMap() {
    for (int i = 0; i < map.size(); i++) {

        for (int j = 0; j < map[i].size(); j++) {
            cout << "|------------|\t";
        }

        cout << endl;

        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j]->getCellType() != "Field") {
                cout << "| " << map[i][j]->getCellType() << " |\t";
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


