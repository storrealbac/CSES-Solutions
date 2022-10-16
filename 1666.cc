#include<bits/stdc++.h>

using namespace std;


void dfs(int node, vector<vector<int>> &adjlist, vector<bool> &visited) {

    visited[node] = true;

    for (int i = 0 ; i < (int)adjlist[node].size(); ++i) {
        
        for (int vecino : adjlist[node])
            if (!visited[vecino])
                dfs(vecino, adjlist, visited);
            
    }

}

int main() {

    int cities, roads;
    scanf("%d%d", &cities, &roads);

    vector<vector<int>> adjlist(cities);
    vector<bool> visited(cities, false);
    vector<int> required_roads;
    
    for (int i = 0; i < roads; ++i) {
        int from_node, to_node;
        scanf("%d%d", &from_node, &to_node);
        from_node--; to_node--;
        adjlist[from_node].push_back(to_node);
        adjlist[to_node].push_back(from_node);
    }

    /*
    for (int i = 0 ; i < (int)adjlist.size(); ++i) {
        printf("i → ", i);

        for (int j = 0; j < adjlist[i].size(); j++) {
            printf("%d ", adjlist[i][j]);
        }

        printf("\n");
    }
    */
   
    dfs(0, adjlist, visited);

    for (int i = 0; i < (int)visited.size(); ++i) {
        if (!visited[i]) {
            required_roads.push_back(i);
            dfs(i, adjlist, visited);
        }
    }

    printf("%ld\n", required_roads.size());
    for (int conex : required_roads) {
        printf("%d 1\n", conex+1);
    }




    return 0;
}