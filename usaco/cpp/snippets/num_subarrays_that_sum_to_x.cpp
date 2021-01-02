//https://cses.fi/problemset/task/1661/

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int len, query;
    cin >> len >> query;
    long long count = 0;
    map<long long, long long> occurences;
    occurences[0]++;
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        long long a;
        cin >> a;
        sum += a;
        count += occurences[sum-query]; //sum-query = a-1 in partial sums, need += in case of arr = [0, ... , 7 ... , 7] and ur looking for sum to be 7
        occurences[sum]++;
    }
    cout << count << endl;
    return 0;
}