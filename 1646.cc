#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, q;
    scanf("%d%d", &n, &q);

    vector<long long> s(n+1);
    long long sum = 0;
    for(int i = 1; i < n+1; ++i) {
        long long x; scanf("%lld", &x);
        sum += x; s[i] = sum;
    }

    for (int i = 0; i < q; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);
        printf("%lld\n", s[to]-s[from-1]);
    }

    return 0;
}