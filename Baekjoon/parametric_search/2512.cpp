// 백준 2512번 = 예산

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, lo, hi, res;
vector<int> v;

bool check(int cost) {
    int sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += v[i] > cost ? cost : v[i];
        if(sum > S) return false;
    }
    return true;

}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cin >> S;

    lo = 0; hi = v[N - 1];

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) {
            lo = mid + 1;
            res = mid;
        }
        else hi = mid - 1;
    }
    cout << res << '\n';

    return 0;
}  