#include<bits/stdc++.h>

using namespace std;


int main() {


    int n; scanf("%d", &n);
    
    vector<pair<long, long>> movies;

    for (int i = 0; i < n; ++i) {

        long start, end;
        scanf("%ld%ld", &start, &end);

        movies.push_back({end, start});

    }

    sort(movies.begin(), movies.end());

    long current = movies[0].first, ans = 1;

    for (int i = 1; i < n; ++i)
        if ( movies[i].second >= current )
            current = movies[i].first, ans++;


    printf("%ld\n", ans);
    return 0;
}