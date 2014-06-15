#include <iostream>
#include <stdio.h> 
#include <curl/curl.h> 
#include <string>

using namespace std;

//int main(void)
//{
//	CURL *curl;
//	CURLcode res;
//
//	string html1;
//	string html2;
//
//	curl = curl_easy_init();
//	if (curl) 
//	{
//		curl_easy_setopt(curl, CURLOPT_URL, "http://djanik.n2.ig.info.pl/checkReady.php");
//
//		res = curl_easy_perform(curl);
//
//	
//
//		/* always cleanup */
//		curl_easy_cleanup(curl);
//
//
//
//	}
//	cout << "\n";
//	cout <<"Tu ma byc.."<< html1<<endl;
//	system("Pause");
//	return 0;
//
//}


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

int main(void)
{
	CURL *curl;
	CURLcode res;
	string readBuffer;

	curl = curl_easy_init();
	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://djanik.n2.ig.info.pl/cgi-bin/run.pl?json=");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		cout <<" tu wywala strigna.... " <<readBuffer << endl;
	}
	system("Pause");
	return 0;

}


//http://djanik.n2.ig.info.pl/cgi-bin/run.pl?json=

//#include <curl/curl.h>
//#include <iostream>
//
//using namespace std;
//
//
//
//	const char data[] = "hejo";
//
//	struct WriteThis
//	{
//		const char *readptr;
//		int sizeleft;
//	};
//
//	static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *userp)
//	{
//		struct WriteThis *pooh = (struct WriteThis *)userp;
//
//		if (size*nmemb) //sizeleft)
//		{
//			*(char *)ptr = pooh->readptr[0]; /* copy one single byte */
//			pooh->readptr++;                 /* advance pointer */
//			pooh->sizeleft--;                /* less data left */
//			return 1;                        /* we return 1 byte at a time! */
//		}
//
//		return 0;                          /* no more data left to deliver */
//	}
//
//	int main(void)
//	{
//		CURL *curl;
//		CURLcode res;
//
//		struct WriteThis pooh;
//
//		pooh.readptr = data;
//		pooh.sizeleft = strlen(data);
//
//		curl = curl_easy_init();
//		if (curl) {
//			/* First set the URL that is about to receive our POST. */
//			curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/index.cgi");
//
//			/* Now specify we want to POST data */
//			curl_easy_setopt(curl, CURLOPT_POST, 1L);
//
//			/* we want to use our own read function */
//			curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
//
//			/* pointer to pass to our read function */
//			curl_easy_setopt(curl, CURLOPT_READDATA, &pooh);
//
//			/* get verbose debug output please */
//			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
//
//			/*
//			If you use POST to a HTTP 1.1 server, you can send data without knowing
//			the size before starting the POST if you use chunked encoding. You
//			enable this by adding a header like "Transfer-Encoding: chunked" with
//			CURLOPT_HTTPHEADER. With HTTP 1.0 or without chunked transfer, you must
//			specify the size in the request.
//			*/
//#ifdef USE_CHUNKED
//			{
//				struct curl_slist *chunk = NULL;
//
//				chunk = curl_slist_append(chunk, "Transfer-Encoding: chunked");
//				res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
//				/* use curl_slist_free_all() after the *perform() call to free this
//				list again */
//			}
//#else
//			/* Set the expected POST size. If you want to POST large amounts of data,
//			consider CURLOPT_POSTFIELDSIZE_LARGE */
//			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)pooh.sizeleft);
//#endif
//
//#ifdef DISABLE_EXPECT
//			/*
//			Using POST with HTTP 1.1 implies the use of a "Expect: 100-continue"
//			header.  You can disable this header with CURLOPT_HTTPHEADER as usual.
//			NOTE: if you want chunked transfer too, you need to combine these two
//			since you can only set one list of headers with CURLOPT_HTTPHEADER. */
//
//			/* A less good option would be to enforce HTTP 1.0, but that might also
//			have other implications. */
//			{
//				struct curl_slist *chunk = NULL;
//
//				chunk = curl_slist_append(chunk, "Expect:");
//				res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
//				/* use curl_slist_free_all() after the *perform() call to free this
//				list again */
//			}
//#endif
//
//			/* Perform the request, res will get the return code */
//			res = curl_easy_perform(curl);
//
//			/* always cleanup */
//			curl_easy_cleanup(curl);
//		}
//		
//	
//
//	system("Pause");
//	return 0;
//}