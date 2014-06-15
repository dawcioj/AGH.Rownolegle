#include <iostream>
#include <time.h>
#include "Graph.h"
#include "GraphGen.h"
#include "Dijkstra.h"
#include "string"
#include <sstream>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	cout<<"Rozpoczynam odliczanie.\n";

	time_t czasStart = time(NULL);

	srand((unsigned)time(NULL));

	GraphGen g1;
	Graph testGraf=g1.Generate(250); // 100 wierzcholkow
	
	Dijkstra test;


	//void Dijkstra::Init(Graph * graph, int s)
	test.Init(&testGraf,2);
	test.FindShortestWay();
	test.showResult();
	
	//cout<<testGraf.ToString();
	

	time_t czasStop = time(NULL);

	printf("Czas wykonania wynosi %.2fsek.", difftime(czasStop, czasStart));
	cout << "\n";
	cout << testGraf.Length()<<"\n";

	system("Pause");
	return 0;
}

//czasomierz
// wiekszy przyklad 5 10 s zadanie jest je zrownoleglac
//  #1 na kilku watkach
//  #2  inny komputer mpi
//  