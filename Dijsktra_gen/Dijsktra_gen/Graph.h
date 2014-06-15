/*
----------------------------------------------------------------------------------------------------
| Plik:             Graph.h
| Opis:             Plik naglówkowy grafu skierowanego.
| Autor:            Dawid Janik
| Data utworzenia:  05.20.2014
----------------------------------------------------------------------------------------------------
*/
#include <sstream>
#include <string>
#include <cstdlib>

#ifndef GRAPH_H
#define GRAPH_H

///nieskonczonosc
#define INFINITY 100000000
#define NULL 0



using namespace std;

/**
* Krawedz
* Kazdy obiekt klasy GraphEdge reprezentuje drogi wychodzdce z wierzcholka.
* Czyli krawedz
*/
class GraphEdge
{
public:

	///Wiercholek docelowy
	int Target;

	///"Dlugosc" drogi - waga
	int Distance;
	
	///Konstruktor domyslny
	GraphEdge();

	///Konstruuktor spametryzowany
	GraphEdge(string tmp);



};

/**
* Wierzcholek.
* Kazdy wierzcholek ma przyporzadkowana liste krawedzi
* atrybut Quantity podaje ilosc krawedzi wychodzadcych z wierzcholka
*/
class GraphVertex
{
public:


	//Tablica krawedzi
	GraphEdge *Edges;

	//Ilosc krawedzi
	int Quantity;

	//
	GraphVertex();
	
	//
	GraphVertex(string tmp);
};

/**
Graf.
*/

class Graph
{
public:

	///ilosc wierzcholkow
	int NumberOfVertices;
	//int NumberOfEdges;
	///tablica przechowywujaca wierzcholki

	GraphVertex *Vertices;
	Graph();
	//~Graph();
	/**
	* Konstruktor.
	* sparametryzowany n - ilosc wierzcholkow
	*/
	Graph(int n);
	//Graph::~Graph();

	/**
	* Funkcja czyszczaca graf.
	* Usuwa wszystkie krawedzie z grafu
	*/
	void Clear();

	/**
	* Funkcja dodajaca nowa krawedz (droge) do grafu.
	* \param edgeNo - //
	* \param srcVertexNo - indeks wierzcholka poczatkowego
	* \param destVertexNo - indeks wierzcholka docelowego
	* \param dist - waga
	*/
	void AddNewEdge(int srcVertexNo, int edgeNo, int destVertexNo, int dist);

	void AddNewEdge(int srcVertexNo, int edgeNo, GraphEdge e);

	/**
	* Funkcja wypisujaca graf na ekran.
	*/
	string ToString();

	/*
	 Funkcja zapisujaca graf do pliku
	*/

	string ToFile();

	/**
	* Funkcja zwracajaca rozmiar grafu w bajtach.
	* \return rozmiar struktury w bajtach
	*/
	int Length();


private:
	/**
	* Funkcja inicjujaca.
	*/
	void m_InitVertices();
};

#endif