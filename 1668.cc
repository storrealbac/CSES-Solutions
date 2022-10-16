#include<bits/stdc++.h>

#define int int64_t

using namespace std;

vector<int> COLOR;
vector<vector<int>> G;
vector<bool> VISITED;

bool dfs(int v) {

    for (int u : G[v]) {
        if (!VISITED[u]) {
            VISITED[u] = true;
            COLOR[u] = !COLOR[v];
            if (!dfs(u))
                return false;
        } else if(COLOR[u] == COLOR[v])
            return false;
    }

    return true;
}

signed main() {

    int V, A;
    cin >> V >> A;

    COLOR.assign(V+1, -1);
    VISITED.assign(V+1, 0);
    G.assign(V+1, vector<int>());

    for (int i = 0; i < A; i++) {
        int from, to;
        cin >> from >> to;

        G[from].push_back(to);
        G[to].push_back(from);
    }


    for (int i = 1; i <= V; i++) {
        if (VISITED[i])
            continue;

        COLOR[i] = 1;
        if (!dfs(i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= V; i++)
        cout << COLOR[i]+1 << " ";
    cout << endl;

    return 0;
}