#include "board.h"

using namespace std;

board::board(int numTiles) {
    this->numTiles = numTiles;
    if (numTiles != 46) return; //if not a standard diplomacy board
    this->tiles = new tile*[numTiles];
    for (int i = 0; i < numTiles; i++) {
        this->tiles[i] = new tile();
    }
    //tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, string owner, char tileType, int numNeighbors, tile** neighbors);
    tile* NAONeighbors[] =  {tiles[9], tiles[5], tiles[18], tiles[1]};
    this->tiles[0] = new tile("NAO", false, false, false, ' ','S', 4, NAONeighbors); //North Atlantic Ocean
    /*tile* NWGNeighbors[] = {tiles[1], tiles[2], tiles[23], tiles[
    this->tiles[1] = new tile("NWG", false, false, false, "", 'S', 6, NWGNeighbors);
    this->tiles[2] = new tile("BAR");
    this->tiles[3] = new tile("NTH");
    this->tiles[4] = new tile("GOB");
    this->tiles[5] = new tile("IRE");
    this->tiles[6] = new tile("HEL");
    this->tiles[7] = new tile("SKA");
    this->tiles[8] = new tile("BAL");
    this->tiles[9] = new tile("MAO");
    this->tiles[10] = new tile("GOL");
    this->tiles[11] = new tile("ADR");
    this->tiles[12] = new tile("BLA");
    this->tiles[13] = new tile("WES");
    this->tiles[14] = new tile("TYR");
    this->tiles[15] = new tile("ION");
    this->tiles[16] = new tile("AEG");
    this->tiles[17] = new tile("EAS"); //water
    this->tiles[18] = new tile("Cly"); //england
    this->tiles[19] = new tile("Edi");
    this->tiles[20] = new tile("Lvp");
    this->tiles[21] = new tile("Yor");
    this->tiles[22] = new tile("Wal");
    this->tiles[23] = new tile("Lon"); //england
    this->tiles[24] = new tile("Nor"); //norse
    this->tiles[25] = new tile("Swe");
    this->tiles[26] = new tile("Den"); //norse
    this->tiles[27] = new tile("Fin"); //russia
    this->tiles[28] = new tile("Stp");
    this->tiles[29] = new tile("Liv");
    this->tiles[30] = new tile("Mos");
    this->tiles[31] = new tile("War");
    this->tiles[32] = new tile("Ukr");
    this->tiles[33] = new tile("Sev"); //russia
    this->tiles[34] = new tile("Arm"); //turkey
    this->tiles[35] = new tile("Syr");
    this->tiles[36] = new tile("Smy");
    this->tiles[37] = new tile("Ank");
    this->tiles[38] = new tile("Con"); //turkey
    this->tiles[39] = new tile("Bul"); //balkan
    this->tiles[40] = new tile("Gre");
    this->tiles[41] = new tile("Alb");
    this->tiles[42] = new tile("Ser");
    this->tiles[43] = new tile("Rum"); //balkan
    this->tiles[44] = new tile("Gal"); //austria-hungary
    this->tiles[45] = new tile("Boh"); */
    for (int i = 0; i < numTiles; i++) std::cout << (*this->tiles[i]) << std::endl;
}

board::~board() {
    for (int i = 0; i < this->numTiles; i++) { //46 is a magic number for number of tiles on a standard diplomacy map, this should by made a parameter in the future
        delete this->tiles[i]; 
    }
    delete[] this->tiles;
}
