#include<bits/stdc++.h>
using namespace std;

int dr[] = {-1, 0,  1, 0};
int dc[] = {0, -1,  0, 1};

int h, w, rooms = 0;

bool limites(int i ,int j) {
    return (i < h && j < w && i >=  0 && j >= 0);
}

void dfs(int i , int j, vector<string> &grid, char x){
    grid[i][j] = x;
    for(int k = 0 ; k < 4 ; k++) {
        int r = i + dr[k];
        int c = j + dc[k];
        if(!limites(r,c))
            continue;

        if(grid[r][c] == '.')
            dfs(r, c, grid, x);
    }
}

int main() {
    scanf("%d%d", &h, &w);
    vector<string> grid(h);

    for (int i = 0; i < h; ++i)
        cin >> grid[i];

    for (int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j] == '.') {
                dfs(i, j, grid, 'x');
                rooms++;
            }
        }   
    }
    printf("%d\n", rooms); 
    return 0;
}