#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> times;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        times.push_back(make_pair(a,b));
    }
    sort(begin(times), end(times), cmp);
    long long reward = 0;
    long long curr_time = 0;
    for (int i = 0; i < n; i++) {
        curr_time += times[i].first;
        reward += times[i].second - curr_time;
    }
    cout << reward << endl;
    return 0;
}