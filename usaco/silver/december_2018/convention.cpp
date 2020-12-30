#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int cows, buses, capacity;
vector<int> times;

void setIO(string name) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
    
}

int numberRequiredBuses(long long timeInterval){
    int curLow= times[0];
    int count = 0;
    int busCount = buses;
    for (int i = 0; i < times.size(); i++) {
        if (times[i]-curLow > timeInterval || count == capacity) {
            //add bus
            curLow = times[i];
            busCount--;
            count = 0;
        }
        count++;
    }
    busCount--; //always use at least 1 bus

    //cout << "numberrequiredbuses:: count: " << count << " , " << timeInterval << endl << flush;
    return buses-busCount;
}

bool check(long long timeInterval) {
    return numberRequiredBuses(timeInterval) <= buses;
}

// search function for when false switches to true. at pos=0, we are false, at pos=max, we are true, function returns first index when check is true
long long search(){ 
    long long pos = 0; long long max = times[times.size()-1]; 
    long long a;
    for(a = max; a >= 1; a /= 2) {
        //cout << "search:: pos:" <<  pos << ", a:" << a << endl << flush;
        while(!check(pos+a)) {
            pos += a;
        }
    }
    pos += 1; // move position to next as we want to return first true position (not last false position) 
            // if we want last false do pos -= 1; 

    //cout << "search2:: pos:" <<  pos << ", a:" << a << endl << flush;

    return pos;
}

int main(){
    setIO("convention");
    cin >> cows >> buses >> capacity;
    for (int i = 0; i < cows; i++) {
        int a;
        cin >> a;
        times.push_back(a);
    }
    sort(times.begin(),times.end());
    cout << search() << endl;
    return 0;
}