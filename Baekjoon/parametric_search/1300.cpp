// 백준 1300번 = K번째 수

// 행렬 - i번째 행을 고려하여 구현
// int 를 넘어가는 input, output 주어지므로 long long 사용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long llong;

llong N, K;

llong check(llong mid) {
    llong cnt = 0;
    for(int i = 1; i <= N; ++i) {
        if(i > mid) break;
        cnt += min(N, mid / i);
    }

    return cnt;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    llong lo = 1;
    llong hi = N * N;

    llong res = 0;

    while(lo <= hi) {
        
        llong mid = (lo + hi) / 2;

        if(check(mid) < K) lo = mid + 1; // check(mid) == K 조건 부여 시 행렬에 없는 답 출력 가능 ex) 3 6 → 5
        else {
            res = mid;
            hi = mid - 1;
        }

    }

    cout << res << '\n';

    return 0;

}