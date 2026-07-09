#include <iostream>
#include <curl/curl.h>
using namespace std;

int main(void){
    CURL *curl= curl_easy_init();
    if (!curl)
    {
        // cout<<stderr ;
        cout<<"init failed";
        return EXIT_FAILURE;
    } // if end

    // set options
    curl_easy_setopt(curl,CURLOPT_URL,"https://weggo.org/");
    
    //perform out action
    CURLcode result= curl_easy_perform(curl);
    if (result != CURLE_OK)
    {
        // cout<<stderr;
        cout<<"download problem: %s\n" , curl_easy_strerror(result); 
    }
    
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
}