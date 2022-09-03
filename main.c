#include "curl/curl.h" //libcurl
#include <stdio.h>
#include <unistd.h> //posix os api

void curl() {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init(); //initialize libcurl easy session

    if(curl) {
        //set curl options for easy handle
        curl_easy_setopt(curl, CURLOPT_URL, "https://google.ca");
        //our url that is redirected will be followed by libcurl.
        //1L is a long parameter of the value 1, meaning that it can follow any location (i.e., of a url)
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        //perform the request of our url
        //res (CURLcode) will grab the return code 
        res = curl_easy_perform(curl);

        //check if the return code is an error (not OK return code)
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s \n", curl_easy_strerror(res));
        }

        //cleanup curl and end the easy handle
        curl_easy_cleanup(curl);
    }
}

int main(void) {
    curl();

    return 0;
}
