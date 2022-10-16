#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m, k, s = 0, j = 0;
    scanf("%d%d%d", &n, &m, &k);

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; ++i)
        scanf("%d", &applicants[i]);

    for (int i = 0; i < m; ++i)
        scanf("%d", &apartments[i]);

    sort(applicants.begin(), applicants.end(), greater<int>());
    sort(apartments.begin(), apartments.end(), greater<int>());

    for(int i = 0; i < n; i++){

        while(applicants[i] + k < apartments[j] && j < m)
            j++;


        if( apartments[j] >= applicants[i] - k  && 
            apartments[j] <= applicants[i] + k && j < m){
            s++;
            j++;
        }
    }

    printf("%d\n", s);

    return 0;
}