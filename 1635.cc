#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

const int MOD = 1e9+7;
int dp[MAX];

int main() {

    int N, W;
    scanf("%d%d", &N, &W);

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    dp[0] = 1;
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < N; i++) {
            if (v[i] <= w)
                dp[w] = (dp[w]+dp[w-v[i]])%MOD;
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}