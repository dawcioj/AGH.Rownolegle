/*
----------------------------------------------------------------------------------------------------
| Plik:             Dijkstra.h
| Opis:             Plik nagl�wkowy dla algorytmu Dijkstry.
| Autor:            Dawid Janik
| Data utworzenia:  05.20.20014
----------------------------------------------------------------------------------------------------
*/
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include "Graph.h"

using namespace std;


// Klasa algorytmu Dijkstry.

class Dijkstra
{
private:
	/// ilosc wierzcholkow z nieobliczona droga
	int m_Q; 

	/// wierzcholek zrodlowy grafu
	int m_S;

	/// tablica do przechowywania wyliczonych odleglosci do kazdego z wierzcholkow
	int *m_D;

	///tablica z wierzcholkami o niepoliczonej drodze
	int *m_N;

	/// graf do policzenia
	Graph m_Graph; 


	/**
	* Przeszukuje zbior N w poszukiwaniu wierzcholka o najkrotszej drodze
	* \return int - indeks wierzcholka ?
	*/
	int MinDistance();

public:
	Dijkstra();
	/**
	* Konstruktor.
	* Inicjalizuje zmienne potrzebne do obliczen, wstepnie wypelnia tablice D
	* \parametr graph - skierowany graf do obliczen
	* \parametr  s - wierzcholek Zrodlowy
	*/
	void Init(Graph * graph, int s);

	/**
	* Odnajduje najkrotsza sciezke od wierzcholka zrodlowego do kazdego z wierzcholkow grafu.
	* \return int* - tablica z odleglosciami
	*/
	int* FindShortestWay();
	/**
	* Wyswietla odleglsci od wierzcholka zrodlowego do pozostalych wiercholkow
	*/
	void showResult();

	///Zwraca Json z wynikiem
	void ShowJson();
};

#endif