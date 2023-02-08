// 백준 10816번 = 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, tmp;

vector<int> v;
vector<int> res;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cin >> M;

    res.resize(M);

    for(int i = 0; i < M; ++i) {
        cin >> tmp;
        int cnt = upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp);

        res[i] = cnt;
    }

    for(int val: res) cout << val << " ";

    return 0;
}