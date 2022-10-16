#include<bits/stdc++.h>

using namespace std;

int main() {

    char c;
    stack<char> palindrome;
    map<char, int> letter;

    while ( (c = getchar() ) != '\n') {

        auto it = letter.find(c);

        if (it == letter.end())
            letter[c] = 1;
        else 
            letter[c]++;

    }
    
    short not_even = 0;
    char odd_char;
    for (pair<char, int> p : letter) {


        if ((p.second % 2) != 0) {
            not_even++;
            odd_char = p.first;
        }

        if (not_even > 1) {
            printf("NO SOLUTION\n");
            return 0;
        }

    }

    for (pair<char, int> p : letter) {

        if (odd_char == p.first)
            continue;

        for (int i = 0; i < p.second/2; i++) {
            printf("%c", p.first);
            palindrome.push(p.first);
        }

    }

    for (int i = 0; i < (letter[odd_char]); i++)
        printf("%c", odd_char);

    while(!palindrome.empty()) {
        printf("%c", palindrome.top());
        palindrome.pop();
    }

    printf("\n");

    return 0;
}