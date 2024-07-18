#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <json/json.h>

using namespace std;

void profitLoss(float open, float close, string name);
void wantTransact(string ans, int amount, float price);
void printData(const Json::Value& stockData);
void sendSignal(float price, float high, float low, char ans, int amount);

#endif