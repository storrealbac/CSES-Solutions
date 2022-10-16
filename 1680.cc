#include<bits/stdc++.h>

#define int int64_t

using namespace std;

stack<int> S;


void topSort(int n, vector<vector<int>> &adjlist, vector<bool> &visited) {

    visited[n] = 1;
    for (int v : adjlist[n]) {
        if (!visited[v]) {
            topSort(v, adjlist, visited);
            S.push(v);
        }
    }
}

signed main() {

    int V, A;
    cin >> V >> A;

    vector<vector<int>> adjlist(V+1);
    vector<vector<int>> traspuesta(V+1);
    vector<int> parent(V+1, 1);

    vector<bool> visited(V+1, false);

    for (int i = 0; i < A; i++) {
        int from, to;
        cin >> from >> to;

        adjlist[from].push_back(to);
        traspuesta[to].push_back(from);
    }

    topSort(1, adjlist, visited);

    if (!visited[V]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> cost(V+1, 0);
    S.push(1);
    while (!S.empty()) {
        int nodo = S.top();

        int mx = 0;
        for (int v : traspuesta[nodo]) {
            if (cost[v] >= mx) {
                mx = cost[v];
                parent[nodo] = v;
            }
        }
        cost[nodo] = mx + 1;
        S.pop();
    }

    cout << cost[V] << endl;
    stack<int> path;
    int actual = V;
 
    path.push(V);
    while (actual != 1) {
        actual = parent[actual];
        path.push(actual);
    }
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;

    return 0;
}