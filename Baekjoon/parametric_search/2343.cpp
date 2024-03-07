// 백준 2343번 = 기타 레슨

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int N, M;

bool check(int size) {

    int idx = 0;
    for(int i = 0; i < M; ++i) {
        int sum = 0;
        while(sum + v[idx] <= size) {
            sum += v[idx]; ++idx;
            if(idx == N) return true;
        }
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    int min_size = 1, max_size = N * 10000; // 한 개의 최대 블루레이 크기 변수로 탐색!
    int mid, result = N * 10000;;
    while(min_size <= max_size) {
        mid = (min_size + max_size) / 2;
        if(check(mid)) {
            result = min(mid, result);
            max_size = mid - 1;
        }
        else min_size = mid + 1;
    }

    cout << result << "\n";

    return 0;
}