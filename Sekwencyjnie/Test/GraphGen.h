#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Graph.h"

#ifndef GRAPH_GEN_H
#define GRAPH_GEN_H


/**
* GraphGen.
* Klasa generujaca losowa strukture grafu !skierowanego!
*
*/
class GraphGen
{
public:
	/**
	* Funkcja generujaca losowy graf skierowany.
	* \param n - ilosc wierzcholkow
	* \return obiekt klasy Graph
	*/
	Graph Generate(int n);
	Graph Generate(string json);
};
#endif