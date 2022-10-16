#include<bits/stdc++.h>

using namespace std;

int main() {

    long n, x, c = 0;
    scanf("%ld%ld", &n, &x);

    vector<long> children(n);

    for(long i = 0; i < n; ++i)
        scanf("%ld", &children[i]);

    sort(children.begin(), children.end(), greater <int> ());

    for (int i = 0, j = n-1; i <= j; ++i) {
        if (i == j)
            ++c;
        else if (children[i] + children[j] <= x)
            ++c, --j;
        else ++c;

    }

    printf("%ld\n", c);

    return 0;
}