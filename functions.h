#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <json/json.h>
#include "constants.h"

using namespace std;

void profitLoss(float open, float close, string name);
void wantTransact(string ans, int amount, float price);
void printData(const Json::Value& stockData);
void sendSignal(float price, float high, float low, char ans, int amount);
int levenshtein(const string& a, const string& b);
vector<string> topThree (const string& s);

#endif