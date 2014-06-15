/*
----------------------------------------------------------------------------------------------------
| Plik:             main.cpp
| Opis:             Funckja main serwera.
| Autor:            Dawid Janik
| Data utworzenia:  06.15.2014
----------------------------------------------------------------------------------------------------
*/

#include <iostream>

#include "Dijkstra.h"
#include "string"
#include <sstream>
#include <cstdio>
#include <ctime>

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "GraphGen.h"
//#include "..\Serwer\json.txt"

using namespace std;

string OpenData(string filename)
{
	ifstream infile;
	string s = "";

	infile.open(filename.c_str()); // open file 
	if (infile)
	{
		
		while (infile)
		{
			getline(infile, s);
			
		}

	}
	else
	{
		cout << "Blad\n";
	}

	return s;
}


int main()
{
	
	string json=OpenData("json.txt");
	//cout << json << endl;

	GraphGen gg;
	Graph g = gg.Generate(json);

//	cout << g.ToFile() <<endl;



	Dijkstra test;


	//void Dijkstra::Init(Graph * graph, int s)
	test.Init(&g, 1);
	test.FindShortestWay();
	//test.showResult();
	
	//cout << "Drugi wynik" << endl;
	
	test.ShowJson();
	


//	cout <<g.ToString();


	

	system("Pause");
	return 0;
}
