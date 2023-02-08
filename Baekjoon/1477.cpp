// 백준 1477번 = 휴게소 세우기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, res;

vector<int> v;

int check(int dist) {

    int cnt = 0, gap;
    for(int i = 1; i < N + 2; ++i) { // 0, L 추가
        gap = v[i] - v[i-1]; // 휴게소 간 거리
        cnt += gap / dist;
        if(gap % dist == 0) cnt--;
    
        if(cnt > M) return true; // 해당 dist 가질 때 배치 가능 → dist ↑ 필요
    }
    return false; // 해당 dist 일 때 배치 가능 + dist ↓ 필요
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> L;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];
    v.push_back(0); v.push_back(L);
    sort(v.begin(), v.end());

    int lo = 1, hi = L, mid;
    
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(check(mid)) { // 해당 case 정답 가능 X
            lo = mid + 1;
        }
        else {
            res = mid; // 해당 case 일 때 res 저장 → 마지막 값 = 결과값
            hi = mid - 1;
        }
    }
    cout << res << '\n';

    return 0;
}