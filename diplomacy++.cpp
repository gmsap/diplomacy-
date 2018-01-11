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
		// must have some way of initializing neighbors
	}
};

struct board
{
public:
	tile NAO; //water
	tile NWG;
	tile BAR;
	tile NTH;
	tile GOB;
	tile IRE;
	tile HEL;
	tile SKA;
	tile BAL;
	tile MAO;
	tile GOL;
	tile ADR;
	tile BLA;
	tile WES;
	tile TYR;
	tile ION;
	tile AEG;
	tile EAS; //water
	tile Cly; //england
	tile Edi;
	tile Lvp;
	tile Yor;
	tile Wal;
	tile Lon; //england
	tile Nor; //norse
	tile Swe;
	tile Den; //norse
	tile Fin; //russia
	tile Stp;
	tile Liv;
	tile Mos;
	tile War;
	tile Ukr;
	tile Sev; //russia
	tile Arm; //turkey
	tile Syr;
	tile Smy;
	tile Ank;
	tile Con; //turkey
	tile Bul; //balkan
	tile Gre;
	tile Alb;
	tile Ser;
	tile Rum; //balkan
	tile Gal; //austria-hungary
	tile Boh;
	tile Tyr;
	tile Vie;
	tile Bud;
	tile Tri; //austria-hungary
	tile Ven; //italy
	tile Apu;
	tile Nap;
	tile Rom;
	tile Tus;
	tile Pie; //italy
	tile Tun; //mediteranean
	tile Naf;
	tile Por;
	tile Spa; //mediteranean
	tile Mar; //france
	tile Gas;
	tile Bur;
	tile Par;
	tile Bre;
	tile Pic; //france
	tile Bel; //low countries
	tile Hol; //low countries
	tile Ruh; //germany
	tile Mun;
	tile Sil;
	tile Pru;
	tile Ber;
	tile Kie; //germany

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
