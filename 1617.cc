#include<bits/stdc++.h>

using namespace std;

#define N 1000000007L;
  
long exponentiation(long base, long exp) { 
    long t = 1L; 
    while (exp > 0) { 
  
        if (exp % 2 != 0) 
            t = (t * base) % N; 
  
        base = (base * base) % N; 
        exp /= 2; 
    } 
    return t % N; 
} 
  

int main() {

    long x;
    scanf("%ld", &x);
    
    printf("%ld\n", exponentiation(2, x));

    return 0;
}