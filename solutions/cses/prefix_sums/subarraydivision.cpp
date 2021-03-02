#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int len;
    cin >> len;
    long long count = 0;
    map<long long, long long> occurences;
    occurences[0]++;
    long long sum = 0;
    long long rem = 0;
    for (int i = 0; i < len; i++) {
        long long a;
        cin >> a;
        sum = ((sum+a)%len+len)%len; //takes care of negative nums
        rem = sum % len;
        count += occurences[sum];
        occurences[sum]++;
    }

    cout << count << endl;
    return 0;
}