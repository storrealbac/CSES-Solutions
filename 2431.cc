#include <bits/stdc++.h>
using namespace std;

long long cc[19]= {
	0,
	9,
	99,
	999,
	9999,
	99999,
	999999,
	9999999,
	99999999,
	999999999,
	9999999999,
	99999999999,
	999999999999,
	9999999999999,
	99999999999999,
	999999999999999,
	9999999999999999,
	99999999999999999,
	999999999999999999
};

long long pos(long long k) {
    long long out = 0;
    for(long long j=18;j>=0;j--) {
        if (k > cc[j]) {
            out += (k-cc[j]) * (j+1);
            k = cc[j];
        }
    }
    return out;
}


int main() {
    long long q;
    scanf("%lld", &q);

    while(q--) {
        long long k;
        scanf("%lld", &k);
        long long low = 0;

        long long hi = 1000000000000000000;
        long long res = 1000000000000000000;
        long long ans_pos;

        long long mid;

        while(low <= hi) {

			mid=(low+hi)/2;

            if(pos(mid) >= k) {
				
                if(res > mid) {
                    res = mid;
                    ans_pos = pos(mid);
                }

                hi = mid-1;
            } else
                low = mid+1;
        }

		string xx = to_string(res);

        cout << xx[xx.size()-1-ans_pos+k] << endl;
    }
	return 0;
}