#include "GraphGen.h"

Graph GraphGen::Generate(int n)
{
	srand((unsigned)time(NULL));

	Graph graph(n);
	int size, target;
	bool found;
	for (int i = 0; i < graph.NumberOfVertices; i++) // i -numer wierzcholka
	{
		graph.Vertices[i].Size = rand() % (n - 1) + 1;
		size = graph.Vertices[i].Size;
		//graph.Vertices[i].Size = 10;
		graph.Vertices[i].Edges = new GraphEdge[size]; //tworzony jesr rozmiar tej tablicy

		for (int j = 0; j < size; j++) // j- numer krawedzi
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


//Graph GraphGen::Generate(string json)
//{
//	srand((unsigned)time(NULL));
//
//	Graph graph(n);
//	int size, target;
//	bool found;
//	for (int i = 0; i < graph.NumberOfVertices; i++) // i -numer wierzcholka
//	{
//		graph.Vertices[i].Size = rand() % (n - 1) + 1;
//		size = graph.Vertices[i].Size;
//		//graph.Vertices[i].Size = 10;
//		graph.Vertices[i].Edges = new GraphEdge[size]; //tworzony jesr rozmiar tej tablicy
//
//		for (int j = 0; j < size; j++) // j- numer krawedzi
//		{
//			found = true;
//			while (found)
//			{
//				found = false;
//				target = rand() % graph.NumberOfVertices;
//				for (int k = 0; k < j; k++)
//				{
//					if (target == graph.Vertices[i].Edges[k].Target) // bo jest zero rowny na poczatku
//					{
//						found = true;
//						break;
//					}
//				}
//				if (target == i)
//				{
//					found = true;
//					continue;
//				}
//			}
//			graph.AddNewEdge(i, j, target, rand() % 10 + 1); //random dla dystansu
//		}
//	}
//	return graph;
//}