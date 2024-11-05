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

// // Function to render a building with the name displayed in the middle
// std::vector<std::string> renderBuilding(const std::string& name) {
//     std::vector<std::string> result;
//     result.push_back("|-----|");  // Adjust the outer box to have a width of 9
//
//     // Create a string from the first character or abbreviation
//     std::string firstChar;
//
//     // Set the abbreviation based on the building name
//     if (name == "Townhall") {
//         firstChar = "TH";  // 2 characters
//     }
//     else if (name == "WasteManagement") {
//         firstChar = "WM";  // 2 characters
//     }
//     else if (name == "TrainStation") {
//         firstChar = "TS";  // 2 characters
//     }
//     else if (name == "SteelFactory") {
//         firstChar = "SF";  // 2 characters
//     }
//     else if (name == "PowerPlant") {
//         firstChar = "PP";  // 2 characters
//     }
//     else if (name == "Police") {
//         firstChar = "PS";  // 2 characters
//     }
//     else if (name == "Airport") {
//         firstChar = "Air";  // 3 characters
//     }
//     else {
//         // Default to the first character if no abbreviation is defined
//         firstChar = std::string(1, name[0]);  // 1 character
//     }
//
//     // Calculate padding to center `firstChar` in a 7-character space (leaving borders)
//     int totalPadding = 5 - firstChar.size();  // Total padding needed for 7 characters
//     int leftPadding = totalPadding / 2;       // Divide evenly for left padding
//     int rightPadding = totalPadding - leftPadding;  // Remainder for right padding
//
//     // Construct the centered line
//     result.push_back("|" + std::string(leftPadding, ' ') + firstChar + std::string(rightPadding, ' ') + "|");
//
//     result.push_back("|-----|");  // Closing box line
//     return result;
// }
//
// // Function to render a field as a box without any name inside
// std::vector<std::string> renderField() {
//     std::vector<std::string> result;
//     result.push_back("-------");
//     result.push_back("-     -");
//     result.push_back("-------");
//     return result;
// }
//
// // Function to render a road as an empty box of the same size
// std::vector<std::string> renderRoad() {
//     std::vector<std::string> result;
//     result.push_back("     ");
//     result.push_back("     ");
//     result.push_back("     ");
//     return result;
// }
//
// void displayMap(const vector<vector<Cell*>> &map) {
//     unordered_set<Cell*> renderedCells;
//
//     for (const auto& row : map) {
//         // Each cell in the row will contribute a set of 5 strings, one for each line of the cell
//         vector<string> line1, line2, line3;
//
//         for (const auto& cell : row) {
//             if (!cell) continue; // Skip null pointers
//
//             // Skip if the cell has already been rendered
//             if (renderedCells.find(cell) != renderedCells.end()) {
//                 continue;
//             }
//             renderedCells.insert(cell);
//
//             // Determine the rendering type based on the cell type
//             vector<string> cellLines;
//             string cellType = cell->getCellType();
//             if (cellType == "Road") {
//                 cellLines = renderRoad();
//             } else if (cellType == "Field") {
//                 cellLines = renderField();
//             } else {
//                 cellLines = renderBuilding(cellType);
//             }
//
//             // Add each line of the cell to the corresponding output line
//             line1.push_back(cellLines[0]);
//             line2.push_back(cellLines[1]);
//             line3.push_back(cellLines[2]);
//         }
//
//         // Print each row of cells as one line
//         for (const auto& line : {line1, line2, line3}) {
//             for (const auto& part : line) {
//                 cout << part << " ";
//             }
//             cout << "\n";
//         }
//     }
// }

std::vector<std::string> renderBuilding(const std::string& name, int widthCells, int heightCells) {
    int cellWidth = 9;    // Width of a single cell (internal space)
    int cellHeight = 3;   // Height of a single cell (internal space)

    int totalWidth = (widthCells * cellWidth) + widthCells - 1; // Total width including borders
    int totalHeight = (heightCells * cellHeight); // Total height including borders

    // cout << name << ": total height = " << totalHeight << endl << endl;

    // Building box
    std::vector<std::string> result(totalHeight, std::string(totalWidth, ' '));

    // Top and bottom borders
    result[0] = std::string(totalWidth, '-');
    result[totalHeight - 1] = std::string(totalWidth, '-');

    // Side borders and interior space
    if (totalHeight > 3) {
        for (int i = 1; i < totalHeight - 1; ++i) {
            result[i] = std::string(totalWidth, ' ');
            result[i][0] = '|';
            result[i][totalWidth - 1] = '|';
        }
    }
    else {
        result[1] = std::string(totalWidth, ' ');
        result[1][0] = '|';
        result[1][totalWidth - 1] = '|';
    }


    // Create abbreviation for the building name
    std::string abbreviation;
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
        // abbreviation = std::string(1, name[0]);
        abbreviation = name[0];
    }

    // Center the abbreviation in the middle of the building
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

// Render a field as an empty box
std::vector<std::string> renderField() {
    std::vector<std::string> result;
    result.push_back("---------");
    result.push_back("-       -");
    result.push_back("---------");
    return result;
}

// Render a road as an empty box
std::vector<std::string> renderRoad() {
    std::vector<std::string> result;
    result.push_back("         ");
    result.push_back("         ");
    result.push_back("         ");
    return result;
}

// Determine if a cell is the top-left of a multi-cell building
bool isTopLeftCellOfBuilding(const vector<vector<Cell*>>& map, int row, int col) {
    if (!map[row][col]) return false;
    return (row == 0 || map[row - 1][col] != map[row][col]) &&
           (col == 0 || map[row][col - 1] != map[row][col]);
}

// Determine the width and height in cells for a building starting at (row, col)
pair<int, int> getBuildingDimensions(const vector<vector<Cell*>>& map, int row, int col) {
    int width = 0, height = 0;

    // Calculate width
    while (col + width < map[row].size() && map[row][col + width] == map[row][col]) {
        width++;
    }

    // Calculate height
    while (row + height < map.size() && map[row + height][col] == map[row][col]) {
        height++;
    }

    return {width, height};
}

// Display the map with multi-cell building rendering
void displayMap(const vector<vector<Cell*>>& map) {
     std::unordered_set<Cell*> renderedCells;

    for (int row = 0; row < map.size(); ++row) {
        int maxLines = 0;
        std::vector<std::vector<std::string>> cellRenders;
        std::vector<int> cellWidths;

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

                std::string cellType = cell->getCellType();
                std::vector<std::string> cellLines = (cellType == "Road") ? renderRoad() :
                                                     (cellType == "Field") ? renderField() :
                                                     renderBuilding(cellType, widthCells, heightCells);

                maxLines = std::max(maxLines, static_cast<int>(cellLines.size()));
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
                std::cout << (lineIndex < cellLines.size() ? cellLines[lineIndex] : std::string(cellWidths[i], ' ')) << " ";
            }
            std::cout << "\n";
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
