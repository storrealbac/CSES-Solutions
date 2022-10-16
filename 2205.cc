#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
int main() {
    int n;
    scanf("%d", &n);
    for (ll i = 0; i < (2 << n); i++) {
        ll b = i >> 1;
        bitset<16> a(i ^ b);
        cout << a.to_string().erase(0, 16 - n) << "\n";
    }
}