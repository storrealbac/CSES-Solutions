#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    long long total = 0, bigger = 0;
 
    for (int i = 0; i < n; ++i) {
        long x;
        scanf("%ld", &x);
        total += x;

        if (x > bigger)
            bigger = x;
    }
 
    long result;

    if (bigger > total/2)
        result = bigger*2;
    else
        result = total;

    printf("%lld\n", result);
 
    return 0;
}