#include<bits/stdc++.h>

using namespace std;

int main() {

    long n;
    scanf("%ld", &n);   

    if ( (n == 2) || ( n == 3) ) {
        printf("NO SOLUTION\n");
        return 0;
    }

    for(long i = 2; i <= n; i+=2)
        printf("%ld ", i);
    
    for(long i = 1; i <= n; i += 2)
        printf("%ld ", i);


    printf("\n");


    return 0;
}