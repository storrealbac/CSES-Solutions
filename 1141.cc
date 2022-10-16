#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    vector<int> songs(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &songs[i]);

    int curr_l = 0, max_l = 0, i = 0, j = 0;
    map<int, int> freq;
    while (j < n) {
        if (freq.find(songs[j]) == freq.end() || freq[songs[j]] == 0) {
            freq[songs[j]]++;
            curr_l++;
            max_l = max(max_l, curr_l);
            j++;
        } else {
            curr_l--;
            freq[songs[i]]--;
            i++;
        }
    }

    printf("%d\n", max_l);

    return 0;
}