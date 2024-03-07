// 백준 2805번 = 나무자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;

bool check(int h) {
    int sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += max(0, v[i] - h);
        if(sum >= M) return true;
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    int lo = 0, hi = 1000000000, res;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(check(mid)) {// 해당 mid 일 때 M 이상 베기 가능 
            res = mid;
            lo = mid + 1;
        }
        else { // 해당 mid 일 때 M 이상 베기 실패
            hi = mid - 1;
        }
    }

    cout << res << '\n';

    return 0;
}