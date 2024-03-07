// 17247번 = 택시 거리

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M, n, res;
vector<pair<int, int> > vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> n;
            if(n) vec.push_back(make_pair(i, j));
        }
    }
    if(vec[1].first > vec[0].first) res += vec[1].first - vec[0].first;
    else res -= vec[1].first - vec[0].first;

    if(vec[1].second > vec[0].second) res += vec[1].second - vec[0].second;
    else res -= vec[1].second - vec[0].second;

    cout << res << '\n';
    return 0;

}