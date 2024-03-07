// 백준 18868번 = 멀티버스

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<pair<int, int>>> v;

int N, M, n;
int cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d %d", &N, &M);
    v.resize(N);

    for(int i = 0; i < N; ++i) {
        v[i].resize(M);
        for(int j = 0; j < M; ++j) {
            scanf("%d", &n);
            v[i][j] = { n, j };
        }
    }

    for(int i = 0; i < N; ++i) sort(v[i].begin(), v[i].end());

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M - 1; ++j) {
            if(v[i][j].first == v[i][j+1].first) v[i][j+1].second = v[i][j].second;
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            bool is_multiverse = true;
            for(int k = 0; k < M; ++k) {
                if(v[i][k].second != v[j][k].second) {
                    is_multiverse = false;
                    break;
                }
            }
            if(is_multiverse) cnt++;
        }
    }

   cout << cnt << '\n';

    return 0;

}