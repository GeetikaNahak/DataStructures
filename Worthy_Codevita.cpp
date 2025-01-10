#include<bits/stdc++.h>
using namespace std;

vector<string> listi;
vector<int> cost;
vector<pair<string, string>> contradictoryPairs;
unordered_map<string, vector<string>> contradictoryList;
vector<int> sum;
int n, m;
int budget;

bool ok(const unordered_set<string>& currentSet, const string& item) {
    for (const string& str : contradictoryList[item]) {
        if (currentSet.find(str) != currentSet.end()) {
            return false;
        }
    }
    return true;
}

int check(int ind, unordered_set<string>& currentSet, int bg) {
    if (ind < 0 || bg <= 0) return 0;
    int np = check(ind - 1, currentSet, bg);
    int p = 0;
    string s = listi[ind];
    if (ok(currentSet, s) && cost[ind] <= bg) {
        currentSet.insert(s);  
        p = sum[ind] + check(ind - 1, currentSet, bg - cost[ind]);
        currentSet.erase(s);
    }
    
    return max(p, np);
}

int getCharSum(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += c - 'a' + 1; 
    }
    return sum;
}

int main() {
    cin >> n >> m;
    listi.resize(n);
    cost.resize(n);
    sum.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> listi[i];
        sum[i] = getCharSum(listi[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        contradictoryPairs.push_back({a, b});
        contradictoryList[a].push_back(b);
        contradictoryList[b].push_back(a);
    }
    cin >> budget;

    unordered_set<string> currentSet;
    int ans = check(n - 1, currentSet, budget);
    cout << ans << endl;

    return 0;
}
