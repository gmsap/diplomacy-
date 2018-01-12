#include <string>

using namespace std;

struct tile {
public:
	string name;
	bool hasSupplyCenter;
	bool holdsFleet;
	bool holdsArmy;
	string owner; //country to most recently own the territory
    char tileType; //'L' for landlocked, 'C' for coastal, 'S' for sea
	tile** neighbors; //an array of pointers to tiles

	tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, string owner, char tileType, int numNeighbors, tile* neighbors) {
		this->name = name;
		this->hasSupplyCenter = hasSupplyCenter;
		this->holdsFleet = holdsFleet;
		this->holdsArmy = holdsArmy;
        this->owner = owner;
        for (int i = 0; i < numNeighbors; i++) {
            this->neighbors[i] = &neighbors[i];    
        }
    }
};


