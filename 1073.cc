#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<long> towers;
    while(n--) {

        long cube;
        scanf("%ld", &cube);

        auto it = upper_bound(towers.begin(), towers.end(), cube);

        if (it == towers.end())
            towers.push_back(cube);
        else
            *it = cube;

    }

    printf("%ld\n", towers.size());


    return 0;
}