#include<bits/stdc++.h>

using namespace std;

int main() {

    long long n, suma;
    scanf("%lld", &n);

    suma = ((n*(n+1))/2);

        if ( (suma % 2) == 0) {
        printf("YES\n");

        vector<int> a, b;
        bool primero = true;

        n++;
        while ( n >= 1 ) {

            if (primero) {

                n--;
                a.push_back(n);
                n--;
                b.push_back(n);

                primero = false;
            } else {
                
                n--;
                b.push_back(n);
                n--;
                a.push_back(n);

                primero = true;
            }

        }

        if (a.back() <= 0)
            a.pop_back();

        if (b.back() <= 0)
            b.pop_back();

        printf("%d\n", a.size());
        for (int i : a)
            printf("%d ", i);


        printf("\n%d\n", b.size());
        for (int i : b)
            printf("%d ", i);
        printf("\n");



    } else {
        printf("NO\n");
    }

    return 0;
}

/*

    7 4 2 1
    6 5 3

    4 1
    3 2

*/