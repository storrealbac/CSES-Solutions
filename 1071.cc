#include<bits/stdc++.h>

using namespace std;

void solve() {

    long long x, y;
    cin >> y >> x;

    if (y > x) {
        // si es par
        if ( (y%2) == 0 )
            cout << (y*y)-x+1 << endl;
        else
            cout << (y-1)*(y-1) + x << endl;
        return; 
    } 
    
    // impar
    if ( (x%2) == 0 )
        cout << (x-1) *(x-1) + y << endl;
    else
        cout << (x*x) - y + 1 << endl;

    return;
}

int main() {

    ios::sync_with_stdio(false);

    long long t; 
    cin >> t;

    while(t--)
        solve();

    cout << endl;

    return 0;
}