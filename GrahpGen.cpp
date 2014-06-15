
/*
----------------------------------------------------------------------------------------------------
| Plik:             GraphGen.cpp
| Opis:             Implementacja klasy generatora grafow.
| Autor:            Dawid Janik
| Data utworzenia:  05.20.2014
----------------------------------------------------------------------------------------------------
*/

#include "GraphGen.h"


vector<string> split(string s, char delim) 
{
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


Graph GraphGen::Generate(int n)
{
	srand((unsigned)time(NULL));

	Graph graph(n);
	int Quantity, target;
	bool found;
	for (int i = 0; i < graph.NumberOfVertices; i++) // i -numer wierzcholka
	{
		graph.Vertices[i].Quantity = rand() % (n - 1) + 1;
		Quantity = graph.Vertices[i].Quantity;
		//graph.Vertices[i].Quantity = 10;
		graph.Vertices[i].Edges = new GraphEdge[Quantity]; //tworzony jesr rozmiar tej tablicy

		for (int j = 0; j < Quantity; j++) // j- numer krawedzi
		{
			found = true;
			while (found)
			{
				found = false;
				target = rand() % graph.NumberOfVertices;
				for (int k = 0; k < j; k++)
				{
					if (target == graph.Vertices[i].Edges[k].Target) // bo jest zero rowny na poczatku
					{
						found = true;
						break;
					}
				}
				if (target == i)
				{
					found = true;
					continue;
				}
			}
			graph.AddNewEdge(i, j, target, rand() % 10 + 1); //random dla dystansu
		}
	}
	return graph;
}


Graph GraphGen::Generate(string json)
{


	int Quantity, target;
	bool found;


	size_t n = count(json.begin(), json.end(), ';');
	int w_size = n + 1;
	Graph graph(w_size);

	string token;
	splitstring s(json);
	vector<string> jsonTab = s.split(';');
	for (int i = 0; i < jsonTab.size(); i++)
	{
		token = jsonTab[i];
		if (token.empty()) continue;

		graph.Vertices[i].Quantity = count(token.begin(), token.end(), ',') + 1;
		Quantity = graph.Vertices[i].Quantity;
		//graph.Vertices[i].Quantity = 10;
		graph.Vertices[i].Edges = new GraphEdge[Quantity]; //tworzony jesr rozmiar tej tablicy

		string token2;
		splitstring s2(token);
		vector<string> jsonTab2 = s2.split(',');
		for (int j = 0; j < jsonTab2.size(); j++)
		{
			token2 = string(jsonTab2[j]);

			GraphEdge e(token2);

			graph.AddNewEdge(i, j, e); //

		}



	}
	
	return graph;

}