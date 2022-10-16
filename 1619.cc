#include<bits/stdc++.h>

using namespace std;

int main() {    

    int n;
    scanf("%d", &n);

    vector<pair<long,long>> times;

    for (int i = 0; i < n; ++i) {
        int joining, leaving;
        scanf("%d%d", &joining, &leaving);

        times.push_back(make_pair(joining, 1));
        times.push_back(make_pair(leaving, -1));
    }

    sort(times.begin(), times.end());

    long currently = 0, max_currently = 0;

    for (pair<int,int> client : times) {
        currently += client.second;
        if (currently > max_currently)
            max_currently = currently;

    }

    printf("%ld\n", max_currently);

        

    return 0;
} 