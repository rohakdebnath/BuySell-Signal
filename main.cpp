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
        if (stockData.empty()) {
            transform(ticker.begin(), ticker.end(), ticker.begin(), [] (char c) {return tolower(c);});
            vector<string> v = topThree(ticker);
            cout << "Did you mean: 1." << v[0] << " or 2. " << v[1] << " or 3. " << v[2] << "?\n";
            int res; cin >> res;
            if ((res >= 4) or (res <= 0)) {
                cout << "Please try another symbol.\n";
                return 0;
            } else {
                ticker = v[res - 1];
                stockData = getStockQuote(ticker, api);
            }
        }
        float open = 0, high = 0, low = 0, close = 0;
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