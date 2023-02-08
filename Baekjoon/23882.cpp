// 백준 23882번 = 알고리즘 수업 - 선택 정렬 2

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int> v;

int N, K, max_idx, cnt;


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d %d", &N, &K);

    v.resize(N);

    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    for(int i = N - 1; i > 0; --i) {
        max_idx = i;

        for(int j = i - 1; j >= 0; --j) {
            if(v[j] > v[max_idx]) max_idx = j;
        }

        if(max_idx != i) {
            swap(v[max_idx], v[i]);
            cnt++;

            if(cnt == K) {
                for(auto val: v) cout << val << ' ';
                cout << '\n';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;

}