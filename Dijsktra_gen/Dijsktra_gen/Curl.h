/*
----------------------------------------------------------------------------------------------------
| Plik:             Curl.h
| Opis:             Naglowek curl-a umozliwiajacy transferowanie plikow ze wsparciem skladni URL
| Autor:            Dawid Janik
| Data utworzenia:  14.06.2014
----------------------------------------------------------------------------------------------------
*/

#include <iostream>

#include <string>
#include <sstream>
#include <cstdio>


#include <curl/curl.h> 


using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

string GetCurl(string adres, string json)
{




	////if (curl)
	////{
	////	curl_easy_setopt(curl, CURLOPT_URL, "http://djanik.n2.ig.info.pl/cgi-bin/run.pl?json=");
	////	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	////	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	////	res = curl_easy_perform(curl);
	////	curl_easy_cleanup(curl);

	////	cout << " tu wywala strigna.... " << readBuffer << endl;
	////}




CURL *curl;
CURLcode res;
string readBuffer;

curl = curl_easy_init();
if (curl)
{
	adres = adres + "?json=" + curl_easy_escape(curl, json.c_str(), 0);
	curl_easy_setopt(curl, CURLOPT_URL, adres.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
	res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	cout << " curl(" << adres << ") res(" << res<<") = " << readBuffer << endl;
	
}
return readBuffer;
}