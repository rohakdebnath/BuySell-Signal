#ifndef CURL_FUNCTIONS_H
#define CURL_FUNCTIONS_H

#include <string>
#include <json/json.h>
using namespace std;

Json::Value getStockQuote (const string& ticker, const string& api);

#endif
