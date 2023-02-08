#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

typedef long long llong;

int N, K;

vector<llong> v;

int check(llong P) {
    int i = 0;
    for(int j = 0; j < K; ++j) {
        llong s = 0;
        while(s + v[i] <= P) {
            s += v[i]; ++i;
            if(i == N) return N;
        }
    }
    return i;
}

int solve() {
    llong left = 0;
    llong right = MAX * MAX;
    llong mid;
    while(right - left > 1) {
        mid = (left + right) / 2;
        int v = check(mid);
        if(v >= N) right = mid;
        else left = mid;
    }

    return right;
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    llong ans = solve();

    cout << ans << '\n';

}