// #include <iostream>
// #include <curl/curl.h>
// #include <string>

// // Callback: libcurl calls this with chunks of the response body
// size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
//     size_t totalSize = size * nmemb;
//     output->append((char*)contents, totalSize);
//     return totalSize;
// }

// int main() {
//     CURL* curl = curl_easy_init();
//     if (!curl) {
//         std::cerr << "Failed to init curl";
//         return 1;
//     }

//     std::string response;

//     curl_easy_setopt(curl, CURLOPT_URL, "weggo.org");
//     curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
//     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

//     CURLcode res = curl_easy_perform(curl);

//     if (res == CURLE_OK) {
//         long http_code = 0;
//         curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
//         std::cout << "HTTP code: " << http_code << std::endl;
//         std::cout << "----- Response body -----" << std::endl;
//         std::cout << response << std::endl;
//     } else {
//         std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
//     }

//     curl_easy_cleanup(curl);
//     return 0;
// }

// #include <iostream>
// #include <curl/curl.h>
// using namespace std;

// int main() {
//     CURL* curl = curl_easy_init();
//     if (!curl) {
//         cout << "init failed" << endl;
//         return EXIT_FAILURE;
//     }

//     curl_easy_setopt(curl, CURLOPT_URL, "https://weggo.org/");
//     curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // don't download the body, just check status

//     CURLcode result = curl_easy_perform(curl);

//     if (result == CURLE_OK) {
//         long status_code;
//         curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
//         cout << "Status code: " << status_code << endl;
//     } else {
//         cout << "Request failed: " << curl_easy_strerror(result) << endl;
//     }

//     curl_easy_cleanup(curl);
//     return EXIT_SUCCESS;
// }

#include <iostream>
#include <curl/curl.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    while (true) {
        CURL* curl = curl_easy_init();
        if (!curl) {
            cout << "init failed" << endl;
        } else {
            curl_easy_setopt(curl, CURLOPT_URL, "https://weggo.org/");
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

            CURLcode result = curl_easy_perform(curl);

            if (result == CURLE_OK) {
                long status_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
                cout << "Status code: " << status_code << endl;
            } else {
                cout << "Request failed: " << curl_easy_strerror(result) << endl;
            }

            curl_easy_cleanup(curl);
        }

        this_thread::sleep_for(chrono::minutes(15));
    }

    return EXIT_SUCCESS;
}