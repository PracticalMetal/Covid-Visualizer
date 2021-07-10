#include <iostream>
#include<curl/curl.h>

#include <iostream>  
#include <curl/curl.h> 
using namespace std;

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *ignorethis)
{
    size_t bytes=itemsize*nitems;
    int linenumber=1;


    cout<<"The size of the chunck is "<<bytes<<" bytes\n";
    //printf("%d:\t",linenumber);
    cout<<linenumber<<":\t";
    for(long unsigned int i=0;i<bytes;i++)
    {
        cout<<buffer[i];
        if(buffer[i]=='\n')
        {
            linenumber++;
            cout<<linenumber<<":\t";
        }
    }
    cout<<"\n\n";
    return bytes;
}

int main()
{
    CURL *curl=curl_easy_init();

    if(!curl)
    {
        fprintf(stderr,"init failed\n");
        return EXIT_FAILURE;
    }

    // set options
    //curl_easy_setopt(curl, CURLOPT_URL, "https://jacobsorber.com");
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.mygov.in/covid-19");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

    // perform actions
    CURLcode result=curl_easy_perform(curl);
    if(result!=CURLE_OK)
    {
        fprintf(stderr, "download problem \n");
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}