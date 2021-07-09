#include <iostream>  
#include <curl/curl.h> 
using namespace std;
 
int main()
{
    CURL *curl=curl_easy_init();

    if(!curl)
    {
        fprintf(stderr,"init failed\n");
        return EXIT_FAILURE;
    }

    // set options
    curl_easy_setopt(curl, CURLOPT_URL, "https://jacobsorber.com");

    // perform actions
    CURLcode result=curl_easy_perform(curl);
    if(result!=CURLE_OK)
    {
        fprintf(stderr, "download problem \n");
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}