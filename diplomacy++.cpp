#include <iostream>
#include <fstream>
#include <string>

using namespace std;  

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
	printMap();
}
