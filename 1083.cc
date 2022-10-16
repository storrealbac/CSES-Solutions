#include<bits/stdc++.h>

using namespace std;

int main() {

    long long suma = 0, n;
    scanf("%lld", &n);
    
    for (long long i = 0; i < n-1; i++) {
        long long x;
        scanf("%lld", &x);
        suma += x;
    }

    n = ( ( n*(n+1) )/2 ) - suma;

    printf("%lld\n", n);


    return 0;
}