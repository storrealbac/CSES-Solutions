#include<bits/stdc++.h>

using namespace std;

int main() {


    int n, sum = 1;
    scanf("%d", &n);

    vector<int> numbers(n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);

	sort(numbers.begin(), numbers.end());

	for (int i = 1; i < n; ++i)
		if (numbers[i] != numbers[i - 1])
            sum++;

    printf("%d\n", sum);

    return 0;
}