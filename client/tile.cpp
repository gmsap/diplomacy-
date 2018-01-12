#include <string>

using namespace std;

struct tile {
public:
	string name;
	bool hasSupplyCenter;
	bool holdsFleet; // bool holdsFleet and bool holdsArmy determine if a tile is landlocked, coastal, or ocean - no char tileType required
	bool holdsArmy;
	char owner; // first letter of the empire to most recently own the territory NOTE: changed from string - there are only 7 possible chars: E, F, G, I, A, R, and T - no string required
	tile** neighbors; //an array of pointers to tiles

	tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, char owner, int numNeighbors, tile* neighbors) {
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