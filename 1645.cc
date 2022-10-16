#include<bits/stdc++.h>

using namespace std;

void remove(int value, stack<pair<int, int>> &nearest) {

    if (value <= nearest.top().first) {
        nearest.pop();
        remove(value, nearest);
    }

}

int main(){

    int n;
    scanf("%d", &n);

    stack<pair<int, int>> nearest;

    nearest.push({0, 0});

    for (int i = 1; i <= n; i++) {

        int value;
        scanf("%d", &value);

        remove(value, nearest);

        printf("%d ", nearest.top().second);
        nearest.push({value, i});

        printf("\n");
    }

    return 0;
}
