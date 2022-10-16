#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    map<long, long> tickets;

    for (int i = 0; i < n; ++i) {
        long value; scanf("%ld", &value);

        auto it = tickets.find(value);

        if (it == tickets.end())
            tickets[value] = 1;
        else it->second++;
    }

    for (int i = 0; i < m; ++i) {

        if (tickets.empty()) {
            printf("-1\n");
            continue;
        }

    /*
          // print content:
    for (auto it=tickets.begin(); it!=tickets.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
            */

        long customer;
        scanf("%ld", &customer);

        auto it = tickets.upper_bound(customer);
        --it;



        if (it->first > customer)
            --it;

        if (it == tickets.end() || it->first > customer)
            printf("-1\n");
        else
            printf("%ld\n", it->first), it->second--;

        if (it->second == 0)
            tickets.erase(it);

    }


    return 0;
}