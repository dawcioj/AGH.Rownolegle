/*
----------------------------------------------------------------------------------------------------
| Plik:             GraphGen.cpp
| Opis:             Implementacja klasy generatora grafow.
| Autor:            Dawid Janik
| Data utworzenia:  05.20.2014
----------------------------------------------------------------------------------------------------
*/
#include "GraphGen.h"

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


	//delimiter dzieli stringa
	string delimiter = ";";
	
	int i = 0;

	size_t pos = 0;
	string token;
	while ((pos = json.find(delimiter)) != std::string::npos)
	{
		token = json.substr(0, pos);
		if (token.empty()) continue;

		graph.Vertices[i].Quantity = count(token.begin(), token.end(), ',') + 1;
		Quantity = graph.Vertices[i].Quantity;
		//graph.Vertices[i].Quantity = 10;
		graph.Vertices[i].Edges = new GraphEdge[Quantity]; //tworzony jesr rozmiar tej tablicy

		size_t pos2 = 0;
		string token2;
		string delimiter2 = ",";
		int j = 0;
		while ((pos2 = json.find(delimiter)) != string::npos) {
			token2 = token.substr(0, pos2); // krawedz

			GraphEdge e(token2);

			graph.AddNewEdge(i, j, e); //

			json.erase(0, pos2 + delimiter2.length());
			j++;
		}



		json.erase(0, pos + delimiter.length());

		i++;
		

	}

	



	return graph;


}