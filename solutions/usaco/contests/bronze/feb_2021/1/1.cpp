#include <bits/stdc++.h>

using namespace std;

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    setIO("1");
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<string,int> cowMap;
    map<string,string> cowYear;
    map<string,int> yearMap;
    string years[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    int idx = 0;
    for (int i = 0; i < 12; i++) {
        idx++;
        yearMap[years[i]] = idx;
    }
    int numCows;
    cin >> numCows;
    cowMap["Bessie"] = 0;
    cowYear["Bessie"] = "Ox";
    for (int i = 0; i < numCows; i++) {
        vector<string> l;
        for (int j = 0; j < 8; j++) {
            string x;
            cin >> x;
            l.push_back(x);
        }
        // for (string x : l) {
        //     cout << x << " ";
        // }
        // cout << endl;
        string c = l[0];
        string c2 = l[l.size()-1];
        string year = l[4];
        string prev = l[3];
        string c2YearName = cowYear[c2];
        if (prev.compare("previous") == 0) {
            int off = yearMap[c2YearName] - yearMap[year];
            if (off <= 0) {
                off += 12;
            }
            int thisCowOff = cowMap[c2] - off;
            cowYear[c] = year;
            cowMap[c] = thisCowOff;
        } else {
            int off = yearMap[year] - yearMap[c2YearName];
            if (off <= 0) {
                off += 12;
            }
            int thisCowOff = cowMap[c2] + off;
            cowYear[c] = year;
            cowMap[c] = thisCowOff;
        }
        if (c.compare("Elsie") == 0) {
            cout << abs(cowMap[c]) << endl;
            break;
        }
    }
    return 0;
}