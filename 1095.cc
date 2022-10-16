#include<bits/stdc++.h>

#define N 1000000007L;

using namespace std;

long exponentiation(long base, long exp) { 
    long t = 1L; 
    while (exp > 0) { 
  
        if (exp % 2 != 0) 
            t = (t * base) % N; 
  
        base = (base * base) % N; 
        exp /= 2; 
    } 
    return t % N; 
} 

void solve() {

    long long base, exp;
    scanf("%lld%lld", &base, &exp);

    printf("%lld\n", exponentiation(base, exp));

    return;
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--)
        solve();

}