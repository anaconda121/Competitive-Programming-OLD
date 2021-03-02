#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>
#include <stdio.h>
#include <iostream>

using namespace std;

char logbuffer[2000];
int numCows, showtime;
vector<int> cows;

void log(char *logstr) {
    //cout << logstr;
}

void setIO(string name, bool includeout=false) { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    if (includeout) {
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int showtimeForNStage(long long numStages){
    
    //cout << "showtimeForNStage:: numStages:" << numStages << endl << flush;
    
    int result = INT_MAX;
    if (numStages >= numCows) {
        //cout <<  "here" << endl << flush;
        result = *max_element(cows.begin(), cows.end());

    } else {

        priority_queue <int, vector<int>, greater<int> > pq (cows.begin(), cows.begin() + numStages); 

        log (sprintf(logbuffer, "showtimeForNStage:: numStages: %d, pq.size: %d \n",  numStages, pq.size()));
        //cout << "showtimeForNStage:: numStages:" <<  numStages << ", pq.size:" << pq.size() << '\n' << flush;

        long long counter = numStages;
        while (counter < numCows) {
            long long temp = pq.top();
            pq.pop();
            pq.push(temp + cows[counter]);

            //cout << "showtimeForNStage:: counter:" << counter << ", took out:" <<  temp << ", added:" << temp + cows[counter] << endl << flush;
            counter++;
        }

        for (int i=0; i<numStages; i++) {
            result = pq.top();
            pq.pop();
        }
    }

    //cout << "showtimeForNStage:: result:" << result << endl << flush;
    return result; 
}

bool check(long long numStages) {
    return showtimeForNStage(numStages) <= showtime;
}

// search function for when false switches to true. at pos=0, we are false, at pos=max, we are true, function returns fast index when check is true
long long search(){ 
    long long pos = 0; long long max = numCows;
    long long a;
    for(a = max; a >= 1; a /= 2) {
        
        //cout << "search:: pos:" <<  pos << ", a:" << a << endl << flush;
        while(!check(pos+a)) pos += a;
    }
    pos += 1; // move position to next as we want to return first true position (not last false position) 

    //cout << "search2:: pos:" <<  pos << ", a:" << a << endl << flush;

    return pos;
}

int main() {
    setIO("cowdance", true);
    cin >> numCows >> showtime;
 
    for (int i = 0; i < numCows; i++) {
        int a;
        cin >> a;
        cows.push_back(a);
    }

    cout << search() << endl;
    return 0;
}