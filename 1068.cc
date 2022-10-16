#include<bits/stdc++.h>

using namespace std;

int main() {

    long n;
    scanf("%ld", &n);

    printf("%ld ", n);
    while(1) {

        if (n == 1)
            break;

        else if ( (n%2) == 0 ) 
            n/=2;
        else
            n = (n*3)+1;
        
        printf("%ld ", n);

    }

    printf("\n");

    return 0;
}