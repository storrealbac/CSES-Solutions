#include<bits/stdc++.h>

using namespace std;

int main() {

    long long caso; scanf("%lld", &caso);
    int sums = 0;
    while (caso > 0) {
        caso /= 5;
        sums += caso;
    }

    printf("%d\n", sums);
    
    return 0;
}