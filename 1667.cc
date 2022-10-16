#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
void pathTracer(int node, stack<int> &path, vector<int> &parent) {

    if (parent[node] == -1)
        return;

    path.push(parent[node]);
    pathTracer(parent[node], path, parent);
}

int main() {

    int v, a;
    scanf("%d%d", &v, &a);

    vector<vector<int>> computers(v);
    vector<int> distance(v, INF);
    vector<int> parent(v);

    for(int i = 0; i < a; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);
        from--; to--;
        computers[from].push_back(to);
        computers[to].push_back(from);
    }

    queue<int> q;
    distance[0] = 0;
    parent[0] = -1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : computers[u]) {
            if (distance[v] > distance[u]+1) {
                distance[v] = distance[u]+1;
                q.push(v);

                parent[v] = u;
            } else if (distance[v] == distance[u]+1)
                parent[v] = u;
        }
    }

    stack<int> path;
    path.push(v-1);
    pathTracer(v-1, path, parent);


    if (path.size() == 2 && a > 2) {
        puts("IMPOSSIBLE");
        return 0;
    }
    printf("%ld\n", path.size());
    while (!path.empty()) {
        printf("%d ", path.top()+1);
        path.pop();
    }

    printf("\n");
       


    return 0;
}