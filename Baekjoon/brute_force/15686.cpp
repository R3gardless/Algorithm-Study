// 백준 15686번 = 치킨 배달

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M;
int chick_map[50][50];
int ans = 1000000000;

vector<pair<int, int>> chick_left;
vector<pair<int, int>> chick_loc;
vector<pair<int, int>> home_loc;

void find_chick(int idx, int depth) { // 살아남은 Chick 집 으로 계산
    if(depth == M) { // 대충 치킨 거리 계산 후 Max 값 비교
        int sum = 0;
        for(int i = 0; i < home_loc.size(); ++i) {
            int min_dist = 9999;
            for(int j = 0; j < M; ++j) {
                int x = home_loc[i].first - chick_left[j].first; x = x > 0 ? x : -x;
                int y = home_loc[i].second - chick_left[j].second; y = y > 0 ? y : -y;
                if(x + y < min_dist) min_dist = x + y;
            }
            sum += min_dist;
        }
        if(sum < ans) ans = sum;
        return;
        
    }
    for(int i = idx; i < chick_loc.size(); ++i) {
        chick_left[depth] = chick_loc[i];
        find_chick(i + 1, depth + 1);
    }
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    chick_left.resize(M);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> chick_map[i][j];
            if(chick_map[i][j] == 2) chick_loc.push_back({i, j});
            else if(chick_map[i][j] == 1) home_loc.push_back({i, j});
        }
    }

    find_chick(0, 0);

    cout << ans << '\n';

    return 0;
}