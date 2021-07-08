#include <iostream>  
#include <curl/curl.h> 
using namespace std;
 
int main()
{
    CURL *curl=curl_easy_init();
    return EXIT_SUCCESS;
}