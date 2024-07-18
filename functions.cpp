#include <bits/stdc++.h>
#include <iostream>
#include "functions.h"

using namespace std;

void profitLoss(float open, float close, string name) {
    float pc = (close - open) / open * 100;
    cout << '\n';
    if (pc > 0) {
        cout << name + " stocks is in profit of " << pc << "%\n";
    } else if (pc < 0) {
        cout << name + " stocks is in loss of " << pc << "%\n";
    } else {
        cout << name + " stocks is in a neutral state of " << pc << "%\n";
    }
}

void wantTransact(char ans, int amount, float price) {
    cout << "Enter the number of stocks you want to buy: \n";
    cin >> amount;
    cout << "Do you want to know the Buying/Selling price?: \n";
    cin >> ans; ans = tolower(ans);
    if (ans == 'y') {
        cout << "The order will cost: " << amount * price << '\n';
    } else if (ans == 'n') {
        cout << "Okay\n";
    } else {
        cout << "Invalid Choice\n";
    }
}

void printData(const Json::Value& stockData) {
    cout << "Data for " << stockData["name"].asString() << ":\n";
    cout <<
        "exchange: " << stockData["exchange"].asString() << "\n" <<
        "currency: " << stockData["currency"].asString() << "\n" <<
        "Open price: " << stof(stockData["open"].asString()) << "\n" <<
        "High price: " << stof(stockData["high"].asString()) << "\n" <<
        "Low price: " << stof(stockData["low"].asString()) << "\n" <<
        "Close price: " << stof(stockData["close"].asString()) << "\n" <<
        "Volume: " << stof(stockData["volume"].asString()) << "\n" <<
        "Change: " << stof(stockData["change"].asString()) << "\n" <<
        "Current Price: " << stof(stockData["close"].asString()) << "\n";
}

void sendSignal(float price, float high, float low, char ans, int amount){
    if(price <= low){
        cout << "Buying recommeded\n";
        wantTransact(ans, amount, price);
    }
    else if(price >= high){
        cout << "Selling recommened\n";
        wantTransact(ans, amount, price);
    }
    else{
        cout << "Not suitable for buying and selling\n\n";
    }
}

