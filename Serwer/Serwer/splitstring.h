/*
----------------------------------------------------------------------------------------------------
| Plik:             splitstring.h
| Opis:             Naglowek klasy vector klasa pomocnicza dzielenie wedlug podanego znaku
| Autor:            Dawid Janik
| Data utworzenia:  11.06.2014
----------------------------------------------------------------------------------------------------
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#ifndef SS_H
#define SS_H

//Klasa dla dzielenia stringu  dla podanego znaku
class splitstring : public string 
{
	
	vector<string> flds;
public:

	splitstring(string s) : string(s) { };
	vector<string>& split(char delim, int rep = 0);
};
#endif