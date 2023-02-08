// 백준 2110번 = 공유기 설치

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;

vector<int> v;

bool check(int dist) {
    int cnt = 1;
    int prev = v[0];
    for(int i = 1; i < N; ++i) {
        if(v[i] - prev >= dist) {
            cnt++;
            prev = v[i];
        }
    }
    if(cnt >= C) return true;
    else return false;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    int low = 0, dist, result = 0;
    int high = v[N-1] - v[0];

    while(low <= high) { // 최대 거리를 변수로 이분 탐색
        dist = (low + high) / 2;
        if(check(dist)) { // 해당 최대 거리를 가졌을 때 모든 공유기 설치 가능! 
            result = max(result, dist); // 해당하는 최대 거리가 정답인지 확인
            low = dist + 1; // 이분 탐색
        }
        else high = dist - 1;
    }

    cout << result << '\n';

    return 0;
}