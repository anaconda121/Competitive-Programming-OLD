#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

const int max = 102;

set<string> cows;
int N;

int main(){
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    fin >> N;
    string cowLog [max];
    int gallons [max];

    for (int i = 0; i < N; i++) {
        fin >> cowLog[i] >> gallons[i];
    }
    cout << cowLog;
    cout << gallons;
    return 0;
}