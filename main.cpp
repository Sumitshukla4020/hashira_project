#include "nlohmann/json.hpp"
#include <bits/stdc++.h>
#include <fstream>
 // Requires: nlohmann/json (header-only)

using namespace std;
using json = nlohmann::json;
typedef unsigned long long ull;
const ull MOD = 2305843009213693951ULL; // Use high MOD to avoid overflow; can be adjusted

// Convert from arbitrary base to decimal
ull convertToDecimal(const string& val, int base) {
    ull result = 0;
    for (char ch : val) {
        int digit;
        if (isdigit(ch)) digit = ch - '0';
        else if (isalpha(ch)) digit = tolower(ch) - 'a' + 10;
        else continue;
        result = result * base + digit;
    }
    return result;
}

// Modular inverse using Fermat's little theorem
ull modinv(ull a) {
    ull res = 1, p = MOD - 2;
    while (p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return res;
}

// Lagrange interpolation to get P(0)
ull lagrange_constant_term(const vector<pair<ull, ull>>& points) {
    int k = points.size();
    ull result = 0;

    for (int i = 0; i < k; ++i) {
        ull xi = points[i].first;
        ull yi = points[i].second;

        ull num = 1, denom = 1;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            ull xj = points[j].first;
            num = (num * ((MOD - xj) % MOD)) % MOD;
            denom = (denom * ((xi - xj + MOD) % MOD)) % MOD;
        }

        ull term = yi * num % MOD * modinv(denom) % MOD;
        result = (result + term) % MOD;
    }

    return result;
}

// Parse JSON and return x, y pairs
vector<pair<ull, ull>> parseJSON(const string& filename, int& k_out) {
    ifstream inFile(filename);
    json j;
    inFile >> j;

    int n = j["keys"]["n"];
    k_out = j["keys"]["k"];

    vector<pair<ull, ull>> points;
    for (auto& [key, val] : j.items()) {
        if (key == "keys") continue;
        ull x = stoull(key);
        int base = stoi(val["base"].get<string>());
        string encoded = val["value"].get<string>();
        ull y = convertToDecimal(encoded, base);
        points.emplace_back(x, y);
    }

    return points;
}

// Main logic
ull solve(const string& jsonPath) {
    int k;
    auto points = parseJSON(jsonPath, k);
    for (auto& p : points) {
        cout << "x = " << p.first << ", y = " << p.second << endl;
    }

    // Try all k-combinations
    map<ull, int> freq;
    vector<bool> select(points.size(), false);
    fill(select.begin(), select.begin() + k, true);

    do {
        vector<pair<ull, ull>> subset;
        for (int i = 0; i < points.size(); ++i) {
            if (select[i]) subset.push_back(points[i]);
        }
        ull c = lagrange_constant_term(subset);
        freq[c]++;
    } while (prev_permutation(select.begin(), select.end()));

    // Return the most frequent constant term
    ull best = 0, maxFreq = 0;
    for (auto& [c, f] : freq) {
        if (f > maxFreq) {
            maxFreq = f;
            best = c;
        }
    }
    return best;
}

int main() {
    cout << "Secret from Testcase 1: " << solve("testcase1.json") << endl;
    cout << "Secret from Testcase 2: " << solve("testcase2.json") << endl;
    return 0;
}
