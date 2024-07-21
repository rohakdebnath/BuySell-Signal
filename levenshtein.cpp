#include <bits/stdc++.h>
#include "functions.h"

int levenshtein(const string& a, const string& b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp ((n + 1), vector<int> (m + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i][j] = i;
                continue;
            }
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    return dp[n][m];
}

vector<string> topThree (const string& s) {
    vector<pair<int, string>> v;
    for (const string& t : companyNames) {
        int distance = levenshtein(s, t);
        string ticker = tickerMapping.at(t);
        v.push_back({distance, ticker});
    }
    sort(v.begin(), v.end());
    vector<string> top;
    for (int i = 0; i < 3; ++i) top.push_back(v[i].second);

    return top;
}