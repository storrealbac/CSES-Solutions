#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> towers;

void hanoi(int n, int a, int b, int c) {
    
    if (n == 1) {
        pair<int, int> p;
        p.first = a;
        p.second = b;

        towers.push_back(p);
        return;
    }

    hanoi(n-1, a, c, b);

    pair<int, int> p;
    p.first = a;
    p.second = b;
    towers.push_back(p);
    
    hanoi(n-1, c, b, a);

}

int main() {

    int n;
    scanf("%d", &n);

    hanoi(n, 1, 3, 2);

    printf("%d\n", towers.size());
    for (pair<int, int> t : towers)
        printf("%d %d\n", t.first, t.second);

    return 0;
}