#include <string>

using namespace std;

struct tile {
public:
	string name;
	bool hasSupplyCenter;
	bool holdsFleet; // bool holdsFleet and bool holdsArmy determine if a tile is landlocked, coastal, or ocean - no char tileType required
	bool holdsArmy;
	char unit;
	char owner; // first letter of the empire to most recently own the territory NOTE: changed from string - there are only 7 possible chars: E, F, G, I, A, R, and T - no string required
	tile** landNeighbors; //an array of pointers neighboring land tiles
	tile** seaNeighbors; //an array of pointers neighboring sea/coast tiles
	//two arrays are rquired here, I believe - there are cases such as york and liverpool where tiles are land neighbors but not sea neighbors

	tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, int numLandNeighbors, tile* landNeighbors, int numSeaNeighbors, tile* seaNeighbors) {
		this->name = name;
		this->hasSupplyCenter = hasSupplyCenter;
		this->holdsFleet = holdsFleet;
		this->holdsArmy = holdsArmy;
        this->owner = owner;

        this->landNeighbors = new tile*[numLandNeighbors];
        this->seaNeighbors = new tile*[numSeaNeighbors];

        for (int i = 0; i < numLandNeighbors; i++) {
            this->landNeighbors[i] = &landNeighbors[i];    
        }
        for (int i = 0; i < numSeaNeighbors; i++) {
            this->seaNeighbors[i] = &seaNeighbors[i];    
        }
    }
};