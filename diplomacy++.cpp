#include <iostream>
#include <fstream>
#include <string>

using namespace std;  

struct tile
{
public:
	bool hasSupplyCenter;
	bool holdsFleet;
	bool holdsArmy;
	char unitType;			//'A' is army, 'F' is fleet, ' ' is empty
	char unitOwner;			//character for the country
	tile* neighbors[1];

	tile(bool hasSupplyCenter = false, bool holdsFleet = true, bool holdsArmy = true, char unitType = ' ', char unitOwner = ' ')
	{
		this->hasSupplyCenter = false;
		this->holdsFleet = true;
		this->holdsArmy = true;
		this->unitType = ' ';			//'A' is army, 'F' is fleet, ' ' is empty
		this->unitOwner = ' ';			//character for the country
		//must have some way of initializing neighbors
	}
};

struct board
{
public:
	tile* tiles[74];
	tiles[0] = new tile("NAO"); //water
	tiles[1] = new tile("NWG");
	tiles[2] = new tile("BAR");
	tiles[3] = new tile("NTH");
	tiles[4] = new tile("GOB");
	tiles[5] = new tile("IRE");
	tiles[6] = new tile("HEL");
	tiles[7] = new tile("SKA");
	tiles[8] = new tile("BAL");
	tiles[9] = new tile("MAO");
	tiles[10] = new tile("GOL");
	tiles[11] = new tile("ADR");
	tiles[12] = new tile("BLA");
	tiles[13] = new tile("WES");
	tiles[14] = new tile("TYR");
	tiles[15] = new tile("ION");
	tiles[16] = new tile("AEG");
	tiles[17] = new tile("EAS"); //water
	tiles[18] = new tile("Cly"); //england
	tiles[19] = new tile("Edi");
	tiles[20] = new tile("Lvp");
	tiles[21] = new tile("Yor");
	tiles[22] = new tile("Wal");
	tiles[23] = new tile("Lon"); //england
	tiles[24] = new tile("Nor"); //norse
	tiles[25] = new tile("Swe");
	tiles[26] = new tile("Den"); //norse
	tiles[27] = new tile("Fin"); //russia
	tiles[28] = new tile("Stp");
	tiles[29] = new tile("Liv");
	tiles[30] = new tile("Mos");
	tiles[31] = new tile("War");
	tiles[32] = new tile("Ukr");
	tiles[33] = new tile("Sev"); //russia
	tiles[34] = new tile("Arm"); //turkey
	tiles[35] = new tile("Syr");
	tiles[36] = new tile("Smy");
	tiles[37] = new tile("Ank");
	tiles[38] = new tile("Con"); //turkey
	tiles[39] = new tile("Bul"); //balkan
	tiles[40] = new tile("Gre");
	tiles[41] = new tile("Alb");
	tiles[42] = new tile("Ser");
	tiles[43] = new tile("Rum"); //balkan
	tiles[44] = new tile("Gal"); //austria-hungary
	tiles[45] = new tile("Boh");
	tiles[46] = new tile("Tyr");
	tiles[47] = new tile("Vie");
	tiles[48] = new tile("Bud");
	tiles[49] = new tile("Tri"); //austria-hungary
	tiles[50] = new tile("Ven"); //italy
	tiles[51] = new tile("Apu");
	tiles[52] = new tile("Nap");
	tiles[53] = new tile("Rom");
	tiles[54] = new tile("Tus");
	tiles[55] = new tile("Pie"); //italy
	tiles[56] = new tile("Tun"); //mediteranean
	tiles[57] = new tile("Naf");
	tiles[58] = new tile("Por");
	tiles[59] = new tile("Spa"); //mediteranean
	tiles[60] = new tile("Mar"); //france
	tiles[61] = new tile("Gas");
	tiles[62] = new tile("Bur");
	tiles[63] = new tile("Par");
	tiles[64] = new tile("Bre");
	tiles[65] = new tile("Pic"); //france
	tiles[66] = new tile("Bel"); //low countries
	tiles[67] = new tile("Hol"); //low countries
	tiles[68] = new tile("Ruh"); //germany
	tiles[69] = new tile("Mun");
	tiles[70] = new tile("Sil");
	tiles[71] = new tile("Pru");
	tiles[72] = new tile("Ber");
	tiles[73] = new tile("Kie"); //germany

	board(){
		//sets up ocean and inland countries
		NAO.holdsArmy = false;
		NWG.holdsArmy = false;
		BAR.holdsArmy = false;
		NTH.holdsArmy = false;
		GOB.holdsArmy = false;
		IRE.holdsArmy = false;
		HEL.holdsArmy = false;
		SKA.holdsArmy = false;
		BAL.holdsArmy = false;
		MAO.holdsArmy = false;
		GOL.holdsArmy = false;
		ADR.holdsArmy = false;
		BLA.holdsArmy = false;
		WES.holdsArmy = false;
		TYR.holdsArmy = false;
		ION.holdsArmy = false;
		AEG.holdsArmy = false;
		EAS.holdsArmy = false;
		Mos.holdsFleet = false;
		War.holdsFleet = false;
		Ukr.holdsFleet = false;
		Ser.holdsFleet = false;
		Gal.holdsFleet = false;
		Boh.holdsFleet = false;
		Tyr.holdsFleet = false;
		Vie.holdsFleet = false;
		Bud.holdsFleet = false;
		Bur.holdsFleet = false;
		Par.holdsFleet = false;
		Ruh.holdsFleet = false;
		Mun.holdsFleet = false;
		Sil.holdsFleet = false;
	};
};

void printMap() 
{
	string line;
	ifstream myfile ("map.txt");
	while (getline(myfile,line))
	{
		cout << line << '\n';
	}
	myfile.close();
}

int main()
{
	string input;
	bool running = true;
	while(running)
	{
		cout << endl << "enter a command (try help)" << endl;
		cin >> input;
		cout << endl;
		
		if(input == "help") {
			cout << "help : shows a list of commands" << endl;
			cout << "display : prints the board" << endl;
			cout << "exit : quits diplomacy++" << endl;
		} else if(input == "display") {
			printMap();
		} else if(input == "exit") {
			running = false;
			cout << "closing diplomacy++" << endl;
		}
	}
}
