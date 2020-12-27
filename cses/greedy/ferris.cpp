#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> kids (n);
    for (int i = 0; i < n; i++) {
        cin >> kids[i];
    }
    sort(begin(kids), end(kids));
    int count = 0;
    int curr_weight = 0;
    int last = n-1;
    int i = 0;
    while (i <= last) {
        if (kids[i]+kids[last] > w) {
            last -= 1; //kid in last idx will get an gondola
        } else {
            //only can be 2 kids max so i and last both need to change
            i += 1;
            last -= 1;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}