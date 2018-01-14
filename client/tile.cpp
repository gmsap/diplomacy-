#include "tile.h"


tile::tile() {
    this->name = "";
    this->hasSupplyCenter = false;
    this->holdsFleet = false;
    this->holdsArmy = false;
    this->owner = ' ';
    this->tileType = ' ';
    this->numNeighbors = 0;
}

tile::tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, char owner, char tileType, int numNeighbors, tile** neighbors) {
    this->name = name;
    this->hasSupplyCenter = hasSupplyCenter;
    this->holdsFleet = holdsFleet;
    this->holdsArmy = holdsArmy;
    this->owner = owner;
    this->tileType = tileType;
    this->numNeighbors = numNeighbors;
    this->neighbors = new tile*[numNeighbors];
    for (int i = 0; i < numNeighbors; i++) {
        this->neighbors[i] = neighbors[i];
    }
}

std::ostream& operator<<(std::ostream& stream, const tile& t) {
    std::cout << "tile[name=" << t.name << ", hasSupplyCenter=" << t.hasSupplyCenter << ", holdsFleet=" << t.holdsFleet << ", holdsArmy=" << t.holdsArmy << ", owner=" << t.owner << ", tileType=" << t.tileType << ", numNeighbors=" << t.numNeighbors << ", neighbors=[";
    for (int i = 0; i < t.numNeighbors; i++) {
        std::cout << t.neighbors[i]->name;
        if (i != t.numNeighbors - 1) std::cout << ", ";
    }
    std::cout << "}}" << std::endl;
    return stream;
}
