#include <iostream>
#include <fstream>
#include <string>

using namespace std;  
/*
struct tile
{
	char unitType = ' ';
	char unitOwner = ' ';
}

struct board
{
	tile* tiles[]
}
*/
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
