#include<bits/stdc++.h>
#define INF LLONG_MAX
#define ll long long

using namespace std;

vector<vector<pair<ll, ll>>> adjlist;
vector<ll> distances;
vector<bool> visited;

void dijkstra() {
    priority_queue<pair<ll, ll>> pq;

    distances[0] = 0;
    pq.push({0, 0});    

    while(!pq.empty()) {
        ll a = pq.top().second; pq.pop();

        if(visited[a])
            continue;

        visited[a] = true;

        for (auto u : adjlist[a]) {
            ll b = u.first, w = u.second;
            if (distances[a]+w < distances[b]) {
                distances[b] = distances[a]+w;
                pq.push({-distances[b], b});
            }
        }
    }

}

int main() {

    ll V, A;
    scanf("%lld%lld", &V, &A);

    adjlist.assign(V, vector<pair<ll, ll>>());
    distances.assign(V, INF);
    visited.assign(V, false);

    for(ll i = 0; i < A; i++) {
        ll from, to, weight;
        scanf("%lld%lld%lld", &from, &to, &weight);
        from--, to--;

        adjlist[from].push_back({to, weight});
    }

    dijkstra();

    for(ll cost : distances)
        printf("%lld ", cost);
    printf("\n");

    return 0;
}