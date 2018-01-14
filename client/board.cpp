#include "board.h"
#include <fstream>
#include <regex>
#include <stdio.h>
#include <string.h>

using namespace std;

board::board(int numTiles) {
    this->numTiles = numTiles;
    if (numTiles != 76) return; //if not a standard diplomacy board
    this->tiles = new tile*[numTiles];
    for (int i = 0; i < numTiles; i++) {
        tiles[i] = new tile();
    }
    // ifstream in ("dump.txt");
    // string str;
    // //Data in the form "yor York 0 0 0 E L 5 edi nth lon wal lvp"
    // std::regex re ("^(\\w{3})\\s+((?:\\S+\\s+)+)(\\d)\\s+(\\d)\\s+(\\d)\\s+([A-Z ])\\s+([A-Z ])\\s+(\\d+)\\s*(.*)");
    // std::smatch match;
    // int index = 0;
    // std::string* neighborAbbs = new std::string[numTiles];
    // int neighborAbbsIndex = 0;
    // while (getline(in, str)) {
    //     if (!regex_match(str, re)) {
    //         std::cout << "Failure to match " << str << std::endl;
    //         continue;
    //     }
    //     std::regex_search(str, match, re);
    //     tiles[index]->init(match.str(1), match.str(2), stoi(match.str(3)), stoi(match.str(4)), stoi(match.str(5)), match.str(6)[0], match.str(7)[0], stoi(match.str(8)));
    //     neighborAbbs[neighborAbbsIndex] = match.str(9);
    //     neighborAbbsIndex++;
    //     index++;
    // }
    // for (int i = 0; i < numTiles; i++) {
    //     std::string str = neighborAbbs[i];
    //     int next = str.find(' ');
    //     int prev = 0;
    //     int numAbbs = 0;
    //     while (str.find(' ', prev) != std::string::npos) {
    //         numAbbs++;
    //         prev = str.find(' ', prev + 1);
    //     }
    //     tile** neighbors = new tile*[numAbbs == 0 ? str.length() == 0 ? 0 : 1 : numAbbs + 1];
    //     prev = 0;
    //     int index = 0;
    //     while (next != std::string::npos) {
    //         std::string sub = str.substr(prev, next - prev);
    //         prev = next + 1;
    //         next = str.find(' ', next + 1);
    //         if (this->find(sub))
    //             neighbors[index] = this->find(sub);
    //         else 
    //             std::cout << "Failure to find " << sub << std::endl;
    //         index++;
    //     }
    //     neighbors[index] = this->find(str.substr(prev));
    //     tiles[i]->arrInit(neighbors);
    //     delete[] neighbors;
    // }

    // for (int i = 0; i < numTiles; i++) {
    //     std::cout << *tiles[i] << std::endl;
    // }
    // delete[] neighborAbbs;
    // return;
    //tile(string name, bool hasSupplyCenter, bool holdsFleet, bool holdsArmy, char owner, char tileType, int numNeighbors, tile** neighbors);
    tile* adrN[] = {tiles[64], tiles[2], tiles[30], tiles[4], tiles[70]};
    tiles[0]->init("adr", "Adriatic Sea", false, false, false, ' ', 'S', 5, adrN); //Adriatic Sea
    tile* aegN[] = {tiles[14], tiles[17], tiles[58], tiles[19], tiles[30], tiles[25]};
    tiles[1]->init("aeg", "Aegean Sea", false, false, false, ' ', 'S', 6, aegN); //Aegean Sea
    tile* albN[] = {tiles[54], tiles[25], tiles[30], tiles[0], tiles[64]};
    tiles[2]->init("alb", "Albania", false, false, false, ' ', 'L', 5, albN); //Albania
    tile* ankN[] = {tiles[10], tiles[5], tiles[58] ,tiles[17]};
    tiles[3]->init("ank", "Ankara", true, false, true, 'T', 'L', 4, ankN); //Ankara
    tile* apuN[] = {tiles[0], tiles[30], tiles[40], tiles[51], tiles[70]};
    tiles[4]->init("apu", "Apulia", false, false, false, 'I', 'L', 5, apuN); //Apulia
    tile* armN[] = {tiles[55], tiles[63], tiles[58], tiles[3], tiles[10]};
    tiles[5]->init("arm", "Armenia", false, false, false, 'T', 'L', 5, armN); //Armenia
    tile* balN[] = {tiles[61], tiles[27], tiles[34], tiles[50], tiles[9], tiles[32], tiles[18], tiles[28]};
    tiles[6]->init("bal", "Baltic Sea", false, false, false, ' ', 'S', 8, balN); //Baltic Sea
    tile* barN[] = {tiles[60], tiles[44], tiles[45]};
    tiles[7]->init("bar", "Barents Sea", false, false, false, ' ', 'S', 3, barN); //Barents Sea
    tile* belN[] = {tiles[43], tiles[29], tiles[52], tiles[15], tiles[47], tiles[21]};
    tiles[8]->init("bel", "Belgium", true, false, false, ' ', 'L', 6, belN); //Belgium
    tile* berN[] = {tiles[50], tiles[56], tiles[39], tiles[32], tiles[6]};
    tiles[9]->init("ber", "Berlin", true, false, true, 'G', 'L', 5, berN); //Berlin
    tile* blaN[] = {tiles[55], tiles[5], tiles[3], tiles[17], tiles[14], tiles[53]};
    tiles[10]->init("bla", "Black Sea", false, false, false, ' ', 'S', 6, blaN); //Black Sea
    tile* bohN[] = {tiles[56], tiles[23], tiles[71], tiles[67], tiles[39]};
    tiles[11]->init("boh", "Bohemia", false, false, false, 'A', 'L', 5, bohN); //Bohemia
    tile* breN[] = {tiles[21], tiles[47], tiles[46], tiles[24], tiles[37]};
    tiles[12]->init("bre", "Brest", true, true, false, 'F', 'L', 5, breN); //Brest
    tile* budN[] = {tiles[23], tiles[53], tiles[54], tiles[64], tiles[71]};
    tiles[13]->init("bud", "Budapest", true, false, true, 'A', 'L', 5, budN); //Budapest
    tile* bulN[] = {tiles[53], tiles[10], tiles[17], tiles[1], tiles[25], tiles[54]};
    tiles[14]->init("bul", "Bulgaria", true, false, false, ' ', 'L', 6, bulN); //Bulgaria
    tile* burN[] = {tiles[8], tiles[52], tiles[39], tiles[36], tiles[24], tiles[46], tiles[47]};
    tiles[15]->init("bur", "Burgundy", false, false, false, 'F', 'L', 7, burN); //Burgundy
    tile* clyN[] = {tiles[41], tiles[45], tiles[20], tiles[33]};
    tiles[16]->init("cly", "Clyde", false, false, false, 'E', 'L', 4, clyN); //Clyde
    tile* conN[] = {tiles[10], tiles[3], tiles[58], tiles[1], tiles[14]};
    tiles[17]->init("con", "Constantinople", true, false, true, 'T', 'L', 5, conN); //Constantinople
    tile* denN[] = {tiles[57], tiles[61], tiles[6], tiles[32], tiles[28], tiles[43]};
    tiles[18]->init("den", "Denmark", true, false, false, ' ', 'L', 6, denN); //Denmark
    tile* easN[] = {tiles[58], tiles[63], tiles[30], tiles[1]};
    tiles[19]->init("eas", "Eastern Mediterannean", false, false, false, ' ', 'S', 4, easN); //Eastern Mediterannean
    tile* ediN[] = {tiles[45], tiles[43], tiles[75], tiles[33], tiles[16]};
    tiles[20]->init("edi", "Edinburgh", true, true, false, 'E', 'L', 5, ediN); //Edinburgh
    tile* engN[] = {tiles[72], tiles[35], tiles[43], tiles[8], tiles[47], tiles[12], tiles[37], tiles[31]};
    tiles[21]->init("eng", "English Channel", false, false, false, ' ', 'S', 8, engN); //English Channel
    tile* finN[] = {tiles[44], tiles[60], tiles[27], tiles[61]};
    tiles[22]->init("fin", "Finland", false, false, false, 'R', 'L', 4, finN); //Finland
    tile* galN[] = {tiles[73], tiles[69], tiles[53], tiles[13], tiles[71], tiles[11], tiles[56]};
    tiles[23]->init("gal", "Galicia", false, false, false, 'A', 'L', 7, galN); //Galicia
    tile* gasN[] = {tiles[12], tiles[46], tiles[15], tiles[36], tiles[59], tiles[37]};
    tiles[24]->init("gas", "Gascony", false, false, false, 'F', 'L', 6, gasN); //Gascony
    tile* greN[] = {tiles[2], tiles[54], tiles[14], tiles[1], tiles[30]};
    tiles[25]->init("gre", "Greece", true, false, false, ' ', 'L', 5, greN); //Greece
    tile* golN[] = {tiles[36], tiles[48], tiles[66], tiles[68], tiles[74], tiles[59]};
    tiles[26]->init("gol", "Gulf of Lyon", false, false, false, ' ', 'S', 6, golN); //Gulf of Lyon
    tile* gobN[] = {tiles[22], tiles[60], tiles[34], tiles[6], tiles[61]};
    tiles[27]->init("gob", "Gulf of Bothnia", false, false, false, ' ', 'S', 5, gobN); //Gulf of Bothnia
    tile* helN[] = {tiles[43], tiles[18], tiles[6], tiles[32], tiles[29]};
    tiles[28]->init("hel", "Helgoland Bight", false, false, false, ' ', 'S', 5, helN); //Helgoland Bight
    tile* holN[] = {tiles[28], tiles[32], tiles[52], tiles[8], tiles[43]};
    tiles[29]->init("hol", "Holland", true, false, false, ' ', 'L', 5, holN); //Holland
    tile* ioN[] = {tiles[0], tiles[2], tiles[25], tiles[1], tiles[19], tiles[65], tiles[58], tiles[40], tiles[4]};
    tiles[30]->init("ion", "Ionian Sea", false, false, false, ' ', 'S', 9, ioN); //Ionian Sea
    tile* iriN[] = {tiles[41], tiles[33], tiles[72], tiles[21], tiles[37]};
    tiles[31]->init("iri", "Irish Sea", false, false, false, ' ', 'S', 5, iriN); //Irish Sea
    tile* kieN[] = {tiles[18], tiles[6], tiles[9], tiles[39], tiles[52], tiles[29], tiles[28]};
    tiles[32]->init("kie", "Kiel", true, true, false, 'G', 'L', 7, kieN); //Kiel
    tile* livN[] = {tiles[16], tiles[20], tiles[75], tiles[72], tiles[31], tiles[41]};
    tiles[33]->init("lvp", "Liverpool", true, false, true, 'E', 'L', 6, livN); //Liverpool
    tile* lvnN[] = {tiles[60], tiles[38], tiles[73], tiles[50], tiles[6], tiles[27]};
    tiles[34]->init("lvn", "Livonia", false, false, false, 'R', 'L', 6, lvnN); //Livonia
    tile* lonN[] = {tiles[75], tiles[43], tiles[21], tiles[72]};
    tiles[35]->init("lon", "London", true, true, false, 'E', 'L', 4, lonN); //London
    tile* marN[] = {tiles[15], tiles[48], tiles[26], tiles[59], tiles[24]};
    tiles[36]->init("mar", "Marseilles", true, false, true, 'F', 'L', 5, marN); //Marseilles
    tile* maoN[] = {tiles[41], tiles[31], tiles[21], tiles[12], tiles[24], tiles[59], tiles[49], tiles[74], tiles[42]};
    tiles[37]->init("mao", "Mid-Atlantic Ocean", false, false, false, ' ', 'S', 9, maoN); //Mid-Atlantic Ocean
    tile* mosN[] = {tiles[60], tiles[55], tiles[69], tiles[73], tiles[34]};
    tiles[38]->init("mos", "Moscow", true, false, true, 'R', 'L', 5, mosN); //Moscow
    tile* munN[] = {tiles[32], tiles[9], tiles[56], tiles[11], tiles[67], tiles[15], tiles[52]};
    tiles[39]->init("mun", "Munich", true, false, true, 'G', 'L', 7, munN); //Munich
    tile* napN[] = {tiles[4], tiles[30], tiles[68], tiles[51]};
    tiles[40]->init("nap", "Naples", true, true, false, 'I', 'L', 4, napN); //Naples
    tile* naoN[] = {tiles[45], tiles[16], tiles[31], tiles[37]};
    tiles[41]->init("nao", "North Atlantic Ocean", false, false, false, ' ', 'S', 4, naoN); //North Atlantic Ocean
    tile* nafN[] = {tiles[37], tiles[74], tiles[65]};
    tiles[42]->init("naf", "North Africa", false, false, false, ' ', 'L', 3, nafN); //North Africa
    tile* nthN[] = {tiles[45], tiles[44], tiles[57], tiles[18], tiles[28], tiles[29], tiles[8], tiles[21], tiles[35], tiles[75], tiles[20]};
    tiles[43]->init("nth", "North Sea", false, false, false, ' ', 'S', 11, nthN); //North Sea
    tile* norN[] = {tiles[45], tiles[7], tiles[60], tiles[22], tiles[61], tiles[57], tiles[43]};
    tiles[44]->init("nor", "Norway", true, false, false, ' ', 'L', 7, norN); //Norway
    tile* nwgN[] = {tiles[41], tiles[43], tiles[7], tiles[44], tiles[20], tiles[16]};
    tiles[45]->init("nwg", "Norwegian Sea", false, false, false, ' ', 'S', 6, nwgN); //Norwegian Sea
    tile* parN[] = {tiles[47], tiles[15], tiles[24], tiles[12]};
    tiles[46]->init("par", "Paris", true, false, true, 'F', 'L', 4, parN); //Paris
    tile* picN[] = {tiles[9], tiles[15], tiles[46], tiles[12], tiles[21]};
    tiles[47]->init("pic", "Picardy", false, false, false, 'F', 'L', 5, picN); //Picardy
    tile* pieN[] = {tiles[67], tiles[70], tiles[66], tiles[26], tiles[36]};
    tiles[48]->init("pie", "Piedmont", false, false, false, 'I', 'L', 5, pieN); //Piedmont
    tile* porN[] = {tiles[37], tiles[59]};
    tiles[49]->init("por", "Portugal", true, false, false, ' ', 'L', 2, porN); //Portugal
    tile* pruN[] = {tiles[6], tiles[34], tiles[73], tiles[56], tiles[9]};
    tiles[50]->init("pru", "Prussia", false, false, false, 'G', 'L', 5, pruN); //Prussia
    tile* romN[] = {tiles[70], tiles[4], tiles[40], tiles[68], tiles[66]};
    tiles[51]->init("rom", "Rome", true, false, true, 'I', 'L', 5, romN); //Rome
    tile* ruhN[] = {tiles[32], tiles[39], tiles[15], tiles[8], tiles[29]};
    tiles[52]->init("ruh", "Ruhr", false, false, false, 'G', 'L', 5, ruhN); //Ruhr
    tile* rumN[] = {tiles[69], tiles[55], tiles[10], tiles[14], tiles[54], tiles[13], tiles[23]};
    tiles[53]->init("rum", "Rumania", true, false, false, ' ', 'L', 7, rumN); //Rumania
    tile* serN[] = {tiles[13], tiles[53], tiles[14], tiles[25], tiles[2], tiles[64]};
    tiles[54]->init("ser", "Serbia", true, false, false, ' ', 'L', 6, serN); //Serbia
    tile* sevN[] = {tiles[38], tiles[5], tiles[10], tiles[53], tiles[69]};
    tiles[55]->init("sev", "Sevastopol", true, true, false, 'R', 'L', 5, sevN); //Sevastopol
    tile* silN[] = {tiles[50], tiles[73], tiles[23], tiles[11], tiles[39], tiles[9]};
    tiles[56]->init("sil", "Silesia", false, false, false, 'G', 'L', 6, silN); //Silesia
    tile* skaN[] = {tiles[44], tiles[61], tiles[18], tiles[6], tiles[43]};
    tiles[57]->init("ska", "Skagerrak", false, false, false, ' ', 'S', 5, skaN); //Skagerrak
    tile* smyN[] = {tiles[3], tiles[5], tiles[63], tiles[19], tiles[1], tiles[17]};
    tiles[58]->init("smy", "Smyrna", true, false, true, 'T', 'L', 6, smyN); //Smyrna
    tile* spaN[] = {tiles[24], tiles[36], tiles[26], tiles[74], tiles[37], tiles[49]};
    tiles[59]->init("spa", "Spain", true, false, false, ' ', 'L', 6, spaN); //Spain
    tile* stpN[] = {tiles[7], tiles[38], tiles[34], tiles[27], tiles[22], tiles[44]};
    tiles[60]->init("stp",  "St. Petersburg", true, true, false, 'R', 'L', 6, stpN); //St. Petersburg
    tile* sweN[] = {tiles[44], tiles[22], tiles[27], tiles[6], tiles[18], tiles[57]};
    tiles[61]->init("swe", "Sweden", true, false, false, ' ', 'L', 6, sweN); //Sweden
    tile* swiN[] = {};
    tiles[62]->init("swi", "Switzerland", false, false, false, ' ', ' ', 0, swiN); //Switzerland
    tile* syrN[] = {tiles[5], tiles[58], tiles[19]};
    tiles[63]->init("syr", "Syria", true, false, false, ' ', 'L', 3, syrN); //Syria
    tile* triN[] = {tiles[71], tiles[13], tiles[54], tiles[2], tiles[0], tiles[70], tiles[67]};
    tiles[64]->init("tri", "Trieste", true, true, false, 'I', 'L', 7, triN); //Trieste
    tile* tunN[] = {tiles[42], tiles[74], tiles[68], tiles[30]};
    tiles[65]->init("tun", "Tunis", false, false, false, ' ', 'L', 4, tunN); //Tunis
    tile* tusN[] = {tiles[70], tiles[51], tiles[68], tiles[26], tiles[48]};
    tiles[66]->init("tus", "Tuscany", false, false, false, 'I', 'L', 5, tusN); //Tuscany
    tile* tyrN[] = {tiles[39], tiles[11], tiles[71], tiles[64], tiles[70], tiles[48]};
    tiles[67]->init("tyr", "Tyrolia", false, false, false, 'A', 'L', 6, tyrN); //Tyrolia
    tile* tysN[] = {tiles[66], tiles[51], tiles[40], tiles[30], tiles[65], tiles[74], tiles[26]};
    tiles[68]->init("tys", "Tyrrhenian Sea", false, false, false, ' ', 'S', 7, tysN); //Tyrrhenian Sea
    tile* ukrN[] = {tiles[38], tiles[55], tiles[53], tiles[23], tiles[73]};
    tiles[69]->init("ukr", "Ukraine", false, false, false, 'R', 'L', 5, ukrN); //Ukraine
    tile* venN[] = {tiles[67], tiles[64], tiles[0], tiles[4], tiles[51], tiles[66], tiles[48]};
    tiles[70]->init("ven", "Venice", true, false, true, 'I', 'L', 7, venN); //Venice
    tile* vieN[] = {tiles[11], tiles[23], tiles[13], tiles[64], tiles[67]};
    tiles[71]->init("vie", "Vienna", true, false, true, 'A', 'L', 5, vieN); //Vienna
    tile* walN[] = {tiles[33], tiles[75], tiles[35], tiles[21], tiles[31]};
    tiles[72]->init("wal", "Wales", false, false, false, 'E', 'L', 5, walN); //Wales
    tile* warN[] = {tiles[34], tiles[38], tiles[69], tiles[23], tiles[56], tiles[50]};
    tiles[73]->init("war", "Warsaw", true, false, true, 'R', 'L', 6, warN); //Warsaw
    tile* wesN[] = {tiles[26], tiles[68], tiles[65], tiles[42], tiles[37], tiles[59]};
    tiles[74]->init("wes", "Western Mediterranean", false, false, false, ' ', 'S', 6, wesN); //Western Mediterranean
    tile* yorN[] = {tiles[20], tiles[43], tiles[35], tiles[72], tiles[33]};
    tiles[75]->init("yor", "York", false, false, false, 'E', 'L', 5, yorN); //York
    


    fstream f ("dump.txt", ios::out | ios::trunc);
    if (!f.good()) std::cout << "Failure to open file 'dump.txt'" << std::endl;
    for (int i = 0; i < numTiles; i++) {
        f << (this->tiles[i]->dump()) << std::endl;
    }
    f.close();
}

board::~board() {
    for (int i = 0; i < this->numTiles; i++) {
        delete this->tiles[i]; 
    }
    delete[] this->tiles;
}

tile* board::find(std::string abb) {
    for (int i = 0; i < this->numTiles; i++) {
        if (this->tiles[i]->abb == abb) return this->tiles[i];
    }
    return nullptr;
}
