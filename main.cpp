#include <bits/stdc++.h>
#include <fstream>
#include <thread>
#include "functions.h"
#include "curlFunctions.h"

int main() {
    cout << "Enter Ticker symbol of a company: ";
    string ticker; cin >> ticker;
    Json::Value config;
    ifstream file("config.json", ifstream::binary);

    if (!file.is_open()) {
        cerr << "Failed to open config file." << endl;
        return 1;
    }
    file >> config;
    file.close();
    string api = config["api_key"].asString();

    while(true) {
        string name, exchange, currency;
        Json::Value stockData = getStockQuote(ticker, api);
        float open, high, low, close;
        float price = 0;
        int amount = 0;
        char ans='\0';

        if (!stockData.empty()) {
            name = stockData["name"].asString();
            exchange = stockData["exchange"].asString();
            currency = stockData["currency"].asString();
            open = stof(stockData["open"].asString());
            high = stof(stockData["high"].asString());
            low = stof(stockData["low"].asString());
            close = stof(stockData["close"].asString());
            if (stockData["is_market_open"].asBool()) {
                price = close;
            } else {
                cout << "Market is not open right now, would you like to proceed with the closing prices or terminate?: (Y/N)\n";
                char c; cin >> c;
                c = tolower(c);
                if (c == 'y') {
                    price = close;
                } else {
                    cout << "Terminating the program.\n";
                    return 0;
                }
            }
        } else {
            cerr << "Failed to fetch Stock Quote\n";
            return 1;
        }
        printData(stockData);
        profitLoss(open, close, name);
        sendSignal(price, high, low, ans, amount);
        if (!stockData["is_market_open"].asBool()) {
            cout << "The program will terminate as the market is closed. Check back tommorow.\n";
            return 0;
        }
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    return 0;
}