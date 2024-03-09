// 1012번 = 유기농 배추

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> vec;
int T, N, M, K, x, y, res;
bool map[50][50], visited[50][50];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void dfs(int r, int c) {
    int nextY, nextX;

    for(int i = 0; i < 4; ++i) {
        nextY = r + dy[i]; nextX = c + dx[i];
        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
        if(visited[nextY][nextX] || !map[nextY][nextX]) continue;
        visited[nextY][nextX] = true;
        dfs(nextY, nextX);
    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    while(T--) {
        
        res = 0;

        cin >> N >> M >> K;
        for(int k = 0; k < K; ++k) {
            cin >> x >> y;
            vec.push_back({x, y});
            map[x][y] = true;
        }

        for(auto v : vec) {
            if(visited[v.first][v.second]) continue;
            visited[v.first][v.second] = true; res++;
            dfs(v.first, v.second);
        
        }

        vec.clear();
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                map[i][j] = false;
                visited[i][j] = false;
            }
        }

        cout << res << '\n';
    }

    return 0;

}