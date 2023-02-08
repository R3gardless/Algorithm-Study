// 백준 1654번 = 랜선 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llong;

int N, K;

vector<llong> v;

bool check(llong dist) {
    
    llong cnt = 0;
    for(int i = 0; i < K; ++i) {
        cnt += v[i] / dist;
        if(cnt >= N) return true;
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N;

    v.resize(K);

    for(int i = 0 ; i < K; ++i) cin >> v[i];

    llong lo = 0, hi = 10000000000, res;

    while(lo <= hi) {
        llong mid = (lo + hi) / 2;

        if(check(mid)) {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << res << '\n';

    return 0;
}