#include<bits/stdc++.h>

using namespace std;


int main() {

    string word;
    cin >> word;

    sort(word.begin(), word.end());
    set<string> permutations; 
    
    do {

        auto it = permutations.find(word);

        if (it == permutations.end())
            permutations.insert(word);

    } while (next_permutation(word.begin(), word.end()));
    
    printf("%d\n", permutations.size());

    for (string word : permutations) {
        cout << word << endl;
    }

    return 0;
}