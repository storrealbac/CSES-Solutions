#include<bits/stdc++.h>
#define INF 10e17
#define MAX 502
#define ll int64_t
using namespace std;

ll dist[MAX][MAX];

int main() {

    ll V, A, Q;
    scanf("%lld%lld%lld", &V, &A, &Q);

    memset(dist, 0x3f, sizeof(dist));
    for(size_t i = 0; i < A; i++) {
        ll from, to, weight;
        scanf("%lld%lld%lld", &from, &to, &weight);

        dist[from][to] = min(dist[from][to], weight);
        dist[to][from] = min(dist[to][from], weight);
    }

    for(size_t i = 1; i <= V; i++)
        dist[i][i] = 0;
    
    for(size_t k = 1; k <= V; k++)
        for(size_t i = 1; i <= V; i++)
            for(size_t j = 1; j <= V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    while(Q--) {
        ll from, to; scanf("%lld%lld", &from, &to);
        (dist[from][to] >= INF) ? printf("-1\n") : printf("%lld\n", dist[from][to]);
    }

    return 0;
}