// 백준 17179번 = 케이크 자르기

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N, M, L, Q, res;

int check(int len) {

    int cnt = 0;

    int prev = 0;
    for(int i = 1; i < M + 2; ++i) {
        if(v[i] - v[prev] >= len) { // 조각의 길이 비교
            prev = i;
            cnt++;
        }
        if(cnt > Q) return true; // 자를 순 있으므로 길이 증가 시켜서 탐색
    }
    return false; // 안되므로 길이 단축
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> L;

    v.resize(M + 2); v[0] = 0; v[M+1] = L;
    for(int i = 1; i < M + 1; ++i) cin >> v[i];

    while(N--) {
        cin >> Q;

        int lo = 0, hi = L; // 결과는 조각의 길이

        while(lo <= hi) {

            int mid = (lo + hi) / 2; // 잘랐을 때 조각의 길이


            if(check(mid)) { // 잘랐을 때 모든 조각이 mid 를 넘겼을 때
                res = mid;
                lo = mid + 1; // 최소 조각의 길이 증가
            }
            else hi = mid - 1; // 잘랐을 때 mid 를 넘지 못하는 조각 발생!
        }
        cout << res << '\n';
    }

    return 0;
}