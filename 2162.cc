#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    set<int> odd;
    bool skip = true;
    for(int i = 1; i <= n; ++i) {
        skip = !skip;
        if (skip) 
            printf("%d ", i);
        else 
            odd.insert(i);
    }

    skip = true;

    if (n%2 == 0)
        skip = false;

    while (!odd.empty()) {

        queue<int> to_remove;
        for (int x : odd) {
            skip = !skip;
            if (skip)
                continue;
            printf("%d ", x);
            to_remove.push(x);
        }

        while (!to_remove.empty())
            odd.erase(to_remove.front()), to_remove.pop();
        
    }
    
    printf("\n");

    return 0;
}