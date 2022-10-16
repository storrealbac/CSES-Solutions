#include<bits/stdc++.h>

using namespace std;


// ^ < > v
int dc[] = {0, -1, 1, 0};
int dr[] = {-1, 0, 0, 1};

int N, M;

bool limit(int i, int j) {
    return (i < N && j < M && i >= 0 && j >= 0);
}

char transform(int dc, int dr) {
    if (dc == 0 and dr == -1)
        return 'L';
    if (dc == -1 and dr == 0)
        return 'U';
    if (dc == 1 and dr == 0)
        return 'D';
    if (dc == 0 and dr == 1)
        return 'R';
    return 'X';
}

signed main() {

    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    // (y, x), type
    queue<pair<pair<int, int>, int>> Q;
    pair<int, int> player;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'M') {
                Q.push({{i, j}, 0});
                grid[i][j] = '#';
            }
            else if (grid[i][j] == 'A') {
                player = {i, j};
            }
        }

    Q.push({player, 1});

    while (!Q.empty()) {
        pair<int, int> pos = Q.front().first;
        int type = Q.front().second;

        Q.pop();

        for (int i = 0; i < 4; i++) {
            int y = pos.first + dr[i];
            int x = pos.second + dc[i];

            // se sale del limite, xao
            if (!limit(y, x))
                continue;

            if (grid[y][x] == '.') {
                if (type == 0)
                    grid[y][x] = '#';
                else
                    grid[y][x] = transform(dr[i], dc[i]);
                Q.push({{y, x}, type});
            }
        }        
    }

    pair<int, int> pos_win = {-1, -1};
    
    // comprobar si ganó

    // borde superior
    for (int i = 0; i < M; i++)
        if (grid[0][i] != '#' and grid[0][i] != '.')
            pos_win = {0, i};

    // borde inferior
    for (int i = 0; i < M; i++)
        if (grid[N-1][i] != '#' and grid[N-1][i] != '.')
            pos_win = {N-1, i};

    // borde izquierdo
    for (int i = 0; i < N; i++)
        if (grid[i][0] != '#' and grid[i][0] != '.')
            pos_win = {i, 0};

    // borde derecho
    for (int i = 0; i < N; i++)
        if (grid[i][M-1] != '#' and grid[i][M-1] != '.')
            pos_win = {i, M-1};

    int y, x;
    y = pos_win.first;
    x = pos_win.second;

    stack<char> path;
    bool ans = 0;
    while (limit(y, x)) {
        path.push(grid[y][x]);
        if (limit(y, x) and grid[y][x] == 'A') {
            ans = 1;
            break;
        } else if (limit(y, x) and grid[y][x] == 'R')
            x--;
        else if (limit(y, x) and grid[y][x] == 'L')
            x++;
        else if (limit(y, x) and grid[y][x] == 'U')
            y++;
        else if (limit(y, x) and grid[y][x] == 'D')
            y--;
    }

    // win
    if (ans) {
        path.pop();
        cout << "YES" << endl;
        cout << path.size() << endl;
        while(!path.empty()) {
            cout << path.top();
            path.pop();
        }
        cout << endl;
    } else
        cout << "NO" << endl;
        
    return 0;
}