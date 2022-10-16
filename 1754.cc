#include<bits/stdc++.h> 

using namespace std;

void solve() {

    long long a, b;
    scanf("%lld%lld", &a, &b);


    if (b > a)
        swap(b, a);
        
    if(b*2 < a) {
        printf("NO\n");
        return;
    }

    if (b%3 > a%3)
        swap(b, a);

    if (a%3 == 2 && b%3 == 1 || a%3==b%3 && b%3==0)
        printf("YES\n");
    else
        printf("NO\n");



    return;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    

    return 0;
}