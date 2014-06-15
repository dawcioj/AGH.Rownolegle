/*
----------------------------------------------------------------------------------------------------
| Plik:             splitstring.cpp
| Opis:             Implementacja klasy vector klasa pomocnicza dzielenie wedlug podanego znaku
| Autor:            Dawid Janik
| Data utworzenia:  11.06.2014
----------------------------------------------------------------------------------------------------
*/
#include "splitstring.h"


vector<string>& splitstring::split(char delim, int rep)
{
	// empty vector if necessary
	if (!flds.empty()) flds.clear();  
	string work = data();
	string buf = "";
	int i = 0;
	while (i < work.length()) {
		if (work[i] != delim)
			buf += work[i];
		else if (rep == 1) {
			flds.push_back(buf);
			buf = "";
		}
		else if (buf.length() > 0) {
			flds.push_back(buf);
			buf = "";
		}
		i++;
	}
	if (!buf.empty())
		flds.push_back(buf);
	return flds;
}