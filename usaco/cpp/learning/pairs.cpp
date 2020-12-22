#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int,int> b) {
    return a.first < b.first || a.second < b.second;
}

int main() {
    //declaring pair
    pair <int,char> p; 

    //intializing values
    p.first = 3;
    p.second = 'f';

    //sorting a vector of pairs
    vector<pair<int, int>> v;
    int arr[] = {10,16,7,14,5,3,12,9};
    for (int i =0; i <sizeof(arr)/sizeof(arr[0]); i++) {
        v.push_back(make_pair(arr[i], i));
    }    

    sort(v.begin(), v.end(), compare); //third param is a comparator, boolean values, helps us decide how to sort vector of pairs

    for(int i = 0; i < v.size(); i++) {
        arr[v[i].second] = i;
    }

    for(int i = 0; i < v.size(); i++) {
        cout << arr[i] << "  --  "  << v[i].second << endl;
    }
    cout << endl;

    return 0;
}