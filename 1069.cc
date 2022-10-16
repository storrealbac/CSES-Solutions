#include<bits/stdc++.h>

using namespace std;

int main() {

    char c, last;

    int max = 0, i = 0;
    while( (c = getchar_unlocked()) != EOF ) {

        if ( c == last) {
            ++i;
            continue;
        }

        if (i > max)
            max = i;
        
        i = 1;
        last = c;
    }

    printf("%d\n", max);

    return 0;
}