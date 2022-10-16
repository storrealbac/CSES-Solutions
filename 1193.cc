#include<bits/stdc++.h>

using namespace std;

// height, width
int h, w;
// A&B, start and end positions
pair<int, int> start, endpos;


/*

    x x x
    x 0 x
    x x x

*/

// movement trick
int dr[] = {-1, 1,  0, 0};
int dc[] = { 0, 0, -1, 1};

// matrix
vector<vector<char>> grid;

void printMatrix() {
    printf("\n");
    for (auto y : grid) {
        for (auto x : y)
            printf("%c", x);
        printf("\n");
    }
}

int direction(int k) {
    switch (k) {
        case 0:
            return 'U';
        case 1:
            return 'D';
        case 2:
            return 'L';
        case 3:
            return 'R';
    }

    return 'Z';
}

bool limit(int i, int j) {
    return (i < h && j < w && i >=  0 && j >= 0);
}

bool bfs(pair<int,int> pos, char x){

   queue<pair<int,int>> q;
   q.push(pos);
   while (!q.empty()) {

       pos = q.front();
       q.pop();

        // movement on grid
        for(int k = 0 ; k < 4 ; k++) {

            int r = pos.first + dr[k];
            int c = pos.second + dc[k];

            if (limit(r, c)) {
                if (grid[r][c] == 'B') {

                    endpos.first = r;
                    endpos.second = c;
                    grid[r][c] = direction(k);

                    return true;
                } else if (grid[r][c] == '.') {
                    grid[r][c] = direction(k);
                    q.push({r, c});
                }

            }
        }

   }

    return false; 
}


int main() {

    scanf("%d%d\n", &h, &w);
    grid.assign(h, vector<char>());

    char c;

    for(int i = 0; i < h; ++i)
        for (int j = 0; (c = getchar_unlocked()) != '\n' && c != EOF; ++j) {
            if (c == 'A')
                start.first = i, start.second = j;

            grid[i].push_back(c);
        }

    if (bfs(start, 'x')) {
        stack<char> path;

        while(1) {

            char path_direction = grid[endpos.first][endpos.second];

            if (path_direction == 'A')
                break;

            path.push(path_direction);

            switch (path_direction) {
                case 'R':
                    --endpos.second;
                    break;

                case 'L':
                    ++endpos.second;
                    break;

                case 'D':
                    --endpos.first;
                    break;

                case 'U':
                    ++endpos.first;
                    break;
            }

        }

        printf("YES\n%ld\n", path.size());
        while(!path.empty()) {
            putchar_unlocked(path.top());
            path.pop();
        }
        printf("\n");
        return 0;
    }

    printf("NO\n");

    return 0;
}