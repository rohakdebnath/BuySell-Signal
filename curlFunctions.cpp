#include <iostream>
#include <string>
#include <curl/curl.h>
#include "curlFunctions.h"

size_t writeCallback(void* recieve, size_t size, size_t nmemb, string* curr) {
    size_t totSize = size * nmemb;
    curr ->append(static_cast<char*>(recieve), totSize);
    return totSize;
}
Json::Value getStockQuote (const string& ticker, const string& api) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "cURL not initialised.\n";
        return Json::Value();
    }
    string jsonRespone, url = "https://api.twelvedata.com/quote?symbol=" + ticker + "&apikey=" + api;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &jsonRespone);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cout << "cURL request failed: " << curl_easy_strerror(res) << '\n';
        return Json::Value();
    }
    curl_easy_cleanup(curl);

    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value core;
    string errors;

    if (!reader ->parse(jsonRespone.c_str(), jsonRespone.c_str() + jsonRespone.size(), &core, &errors)) {
        cerr << "Failed to parse Json: " << errors << '\n';
        return Json::Value();
    }
    delete reader;
    return core;
}
