#include<bits/stdc++.h>

using namespace std;

int main() {

    long n, last, moves = 0;
    scanf("%ld%ld", &n, &last);
    n--;

    while(n--) {
        long x;
        scanf("%ld", &x);

        if (last > x) {
            moves += last-x;
            continue;
        }

        last = x;

    }

    printf("%ld\n", moves);

    return 0;
}