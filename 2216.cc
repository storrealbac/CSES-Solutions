#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<int> indexs(n);
    vector<int> numbers(n);

    for(int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);
        indexs[value] = i;
        numbers[i] = value;
    }

    /*
    for (int x : indexs)
        printf("%d ", x);

    printf("\n");
    */
    int rounds = 1;
    for (int i = 1; i < n; ++i) {
        if (indexs[i] >= indexs[i+1])
            rounds++;
    }

    printf("%d\n", rounds);

    return 0;
}