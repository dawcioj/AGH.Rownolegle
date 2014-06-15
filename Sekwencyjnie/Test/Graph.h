#include <sstream>
#include <string>

#ifndef GRAPH_H
#define GRAPH_H


#define INFINITY 100000000 ///nieskonczonosc
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
	
	int Target; ///Wiercholek docelowy
	
	int Distance; ///"Dlugosc" drogi - waga
};

/**
* Wierzcholek.
* Kazdy wierzcholek ma przyporzadkowana liste krawedzi
* atrybut Size podaje ilosc krawedzi wychodzadcych z wierzcholka
*/
class GraphVertex
{
public:
	
	GraphEdge *Edges; ///Tablica krawedzi
	
	int Size;///Ilosc krawedzi
};

/**
* Graf.
*/

class Graph
{
public:
	
	int NumberOfVertices;///ilosc wierzcholkow
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

	/**
	* Funkcja wypisujaca graf na ekran.
	*/
	string ToString();

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