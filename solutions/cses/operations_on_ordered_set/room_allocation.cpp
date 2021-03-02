#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int customers;
vector<pair<pair<int,int>, int>> everything; //nested pair is for times, int is for room #

int main(){
    cin >> customers;
    int ans[20005];
    for (int i = 0; i < customers; i++) {
        int a,b;
        cin >> a,b;
        everything.push_back(make_pair(make_pair(a,b), i));
    }
    sort(everything.begin(), everything.end());
    priority_queue <pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>>> depature; // creates min pq 
    //first val = depature time
    //second val = room #
    int rooms = 0, last_room = 0;
    for (int i = 0; i < customers; i++) {
        if (depature.empty()) {
            last_room++;
            depature.push(make_pair(everything[i].first.second, last_room));
            ans[everything[i].second] = last_room;
        } else {
            pair<int, int> minimum = depature.top();
            if (minimum.first < everything[i].first.first) {
                depature.pop();
                depature.push(make_pair(everything[i].first.first, minimum.second));
                ans[everything[i].second] = minimum.second;
            } else {
                last_room++;
                depature.push(make_pair(everything[i].first.second,last_room));
                ans[everything[i].second] = last_room;
            }
        }
        rooms = max(rooms, int(depature.size()));
    }
    cout << rooms << "\n";
    for (int i = 0; i < customers; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}