#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

struct Triangle {
    int x;
    int y;
    int bx;
    int by;
    int b2x;
    int b2y;
    bool overlap;
};

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
}

Triangle base(int x, int y) {
    struct Triangle t;
    t.x = x; t.y = y;
    t.bx = (x-y); // tan 45 = 1
    t.by = 0;
    t.b2x = x + y;
    t.b2y = 0;
    t.overlap = false;
    return t;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3) { 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {    
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
   float A1 = area (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
   float A2 = area (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
   float A3 = area (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   //cout << A << " , " << A1 << " , " << A2 << " , " << A3 << " , " << counter << " , " << one << endl;
   return (A == (A1 + A2 + A3)); 
} 

bool cmp (Triangle a, Triangle b) {
    return a.y > b.y;
}

int main() {
    setIO("mountains");
    int n;
    cin >> n;
    vector<Triangle> m (n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].x >> m[i].y;
        m[i] = base(m[i].x, m[i].y);
    }
    sort(begin(m), end(m), cmp);
    int count = n;
    for (int i = 0; i < n; i++) {
        bool overlap;
        for (int j = 0; j < n; j++) {
            if (i != j && m[i].x > m[j].x || m[i].y > m[j].y) {
                overlap = isInside(m[i].x, m[i].y, m[i].bx, m[i].by, m[i].b2x, m[i].b2y, m[j].x, m[j].y);
                if (overlap) {
                    //cout << " 1 " << m[i+1].x << " , " << m[i+1].y << " , " << i << " , " << "True" <<endl;
                    if (m[j].overlap == false) {
                        m[j].overlap = true;
                        count--;
                    }
                }
            }
        }
        //cout << "\n\n" << overlap << endl;
        //bool overlap2 = isInside(m[i].x, m[i].y, m[i].bx, m[i].by, m[i].b2x, m[i].b2y, m[i-1].x, m[i-1].y, i, "overlap2");
        //cout << m[i].x << overlap << " , " << overlap2 << " , " << i << endl;
    }
    cout << count << endl;
}