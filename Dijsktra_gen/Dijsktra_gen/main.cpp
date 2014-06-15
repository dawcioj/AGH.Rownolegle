/*
----------------------------------------------------------------------------------------------------
| Plik:             main.cpp
| Opis:             Funckja main clienta.
| Autor:            Dawid Janik
| Data utworzenia:  06.15.2014
----------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <time.h>
#include "Graph.h"
#include "GraphGen.h"
#include "Curl.h"
#include "splitstring.h"

#include <string>
#include <sstream>
#include <cstdio>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

#include <curl/curl.h> 


using namespace std;


void Translate(string json)
{
	string token;
	splitstring s(json);
	//cout << json << endl;
	vector<string> jsonTab = s.split(',');
	//cout << jsonTab.size() << endl;
	for (int i = 0; i < jsonTab.size(); i++)
	{
		token = jsonTab[i];
		//cout << token << endl;

		string token2;
		splitstring s2(token);
		vector<string> jsonTab2 = s2.split(':');
		for (int j = 0; j < jsonTab2.size(); j++)
		{
			token2 = string(jsonTab2[j]);
			
			if (j == 0)
			{
				cout << "Vertex="<<token2 << "\t";
			}
			else
			{
				cout << "Distance= " << token2 << "\n";
			}
						
		}

	}


}

int main()
{
	//cout << "Rozpoczynam odliczanie.\n";

	time_t czasStart = time(NULL);

	srand((unsigned)time(NULL));

	int ilosc = 20;
	string json;

	GraphGen g1;
	Graph testGraf = g1.Generate(ilosc); // 100 wierzcholkow

	//cout << testGraf.ToString();
	json = testGraf.ToFile();

	string wynik;

	wynik = GetCurl("http://djanik.n2.ig.info.pl/cgi-bin/run.pl" , json);
	cout << "#########################" << endl;
	cout << "#Licze dla werzcholka 1  " << endl;
	cout << "#########################\n";
	Translate(wynik);
	
	//wynik = GetCurl("http://www.onet.pl/", json);
	//cout << wynik << endl;
	

	//Dijkstra test;


	//void Dijkstra::Init(Graph * graph, int s)
	//test.Init(&testGraf, 1);
	//test.FindShortestWay();
	//test.showResult();

//	cout << testGraf.ToString();


	//time_t czasStop = time(NULL);

	//printf("Czas wykonania wynosi %.2fsek.", difftime(czasStop, czasStart));
//	cout << "\n";
	//cout << testGraf.Length() << "\n";

	system("Pause");
	return 0;
}

