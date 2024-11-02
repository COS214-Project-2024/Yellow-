//
// Created by sjvr0 on 2024/10/22.
//

#include "Map.h"
Map::Map(vector<vector<Cell*>> map, vector<vector<int>> distanceMatrix, vector<Cell*> pos)
        : map(map), distanceMatrix(distanceMatrix) {}

Map::Map(){
    map = vector<vector<Cell*>>();
    distanceMatrix = vector<vector<int>>();

    int rows = 200;
    int cols = 200;

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

void Map::addNode(Cell *object) {
    int x;
    int y;
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
    pos.push_back(object);

}

void Map::djikstrasAneurysm(Cell* object){//roads are just meant to me straight
    int pos = findIndex(object);
    double modifier = 2;
    int dist = 0;
    int index1, index2;
    setRoadConnections();
    Road* road;
    if (object->getCellType() == "Road"){
        return;
    }
    vector<Cell*> borderRoads = findBorderRoads(object);
    for (int K = 0; K < borderRoads.size(); ++K){
        road = (Road*) findObject(borderRoads[K]->getCoordinates()[0]);
        for (int i = 0; i < buildings.size(); ++i){
            if (road->sameStreet(buildings[i], object)){
                dist = coordDiff(buildings[i], object);
                index1 = findIndex(buildings[i]);
                index2 = findIndex(object);
                distanceMatrix[index1][index2] = dist;
                distanceMatrix[index2][index1] = dist;
            }
        }
    }

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

int Map::coordDiff(Cell *ob1, Cell *ob2) {
    int diff = 99999;
    vector<Coordinate> ob1coords = ob1->getCoordinates();
    vector<Coordinate> ob2coords = ob2->getCoordinates();
    for (int K = 0; K < ob1coords.size(); ++K){
        for (int i = 0; i < ob2coords.size(); ++i){
            if (((ob1coords[K].x - ob2coords[i].x) + (ob1coords[K].y - ob2coords[i].y)) < diff){
                diff = ((ob1coords[K].x - ob2coords[i].x) + (ob1coords[K].y - ob2coords[i].y));
            }
        }
    }
    return diff + 2;//plus 2 for moving from building to road
}


