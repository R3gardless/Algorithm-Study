// 10026번 = 적록색약

#include <iostream>

using namespace std;

int N, res1, res2;
char map[100][100];
bool visited[100][100];

int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

// dfs 로직 방문 시 true 로 바꾸고 기저 조건 추가하는 방향으로 변경
void dfs(int y, int x) {
    int nextY, nextX;

    if(visited[y][x]) return; // 해당 로직 구현

    visited[y][x] = true; // 해당 로직 구현

    for(int i = 0; i < 4; ++i) {
        nextY = y + dy[i]; nextX = x + dx[i];
        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
        if(visited[nextY][nextX] || (map[y][x] != map[nextY][nextX])) continue;

        dfs(nextY, nextX);
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visited[i][j]) {
                res1++;
                dfs(i, j);
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            visited[i][j] = false;
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!visited[i][j]) {
                res2++;
                dfs(i, j);
            }
        }
    }

    cout << res1 << " " << res2;

    return 0;
}