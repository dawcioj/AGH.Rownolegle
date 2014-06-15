#include "Dijkstra.h"
#include <iostream>
#include <omp.h>

using namespace std;

Dijkstra::Dijkstra(){}

#ifdef _OPENMP
cout << "Kompilator rozpoznaje dyrektywy OpenMP\n";
#endif

void Dijkstra::Init(Graph * graph, int s)
{
	m_Q = 0;
	m_S = s;
	m_Graph = *graph;
	int n = graph->NumberOfVertices;

	m_D = new int[n];
	m_N = new int[n];
	#pragma omp parallel
	#pragma omp for schedule(dynamic,4)
	for (int i = 0; i < n; i++)
	{
#pragma omp parallel
#pragma omp for schedule(dynamic,4)
		m_D[i] = INFINITY;
		if (i == s)
			continue;
		m_N[m_Q++] = i;
	}


#pragma omp for schedule(dynamic,4)private(i)	
	for (int i = 0; i < graph->Vertices[s].Size; i++)
	{
		m_D[graph->Vertices[s].Edges[i].Target] = graph->Vertices[s].Edges[i].Distance;
	}
	m_D[s] = 0;
}

int Dijkstra::MinDistance()
{

	/// index wierzcholka o najmniejszej drodze w N
	int minIndex = 1;
	for (int i = 2; i < m_Q; i++)
	{
		if (m_D[m_N[i]] < m_D[m_N[minIndex]])
			minIndex = i;
	}
	/// wartosc drogi dla wierzcholka o najmniejszes drodze
	int result = m_N[minIndex];

	m_Q--;

	m_N[minIndex] = m_N[m_Q];

	return result;
}

int* Dijkstra::FindShortestWay()
{
	// index wierzcholka dla którego droga zostala wlsnie policzona
	int counted;
	while (m_Q > 0) // dopoki nie sa obliczone wszystkie wierzcholki
	{
		counted = MinDistance(); // przypisz nr wierzcholka o najmniejszej tymczasowej odleglosci
		m_Q--;
		m_N[counted] = m_N[m_Q];
		
	  // #pragma omp parallel for schedule(dynamic,1)
		for (int i = 0; i < m_Graph.Vertices[counted].Size; i++) // sprawdz krawedzie wierzcholka i 
		{
			// jesli znaleziono najkrotsza droge do wiercholka 
			if (m_D[m_Graph.Vertices[counted].Edges[i].Target] > m_D[counted] + m_Graph.Vertices[counted].Edges[i].Distance)
			{
				// to przypisz to droge do struktury "D"
				m_D[m_Graph.Vertices[counted].Edges[i].Target] = m_D[counted] + m_Graph.Vertices[counted].Edges[i].Distance;
			}
		}
	}
	
	return m_D;
}

void Dijkstra::showResult()
{
	cout << "\nWyniki dla wierzcholka : " << m_S << "\n";
	for (int i = 0; i < m_Graph.NumberOfVertices; i++)
		cout << i << " " << m_D[i] << endl;
}