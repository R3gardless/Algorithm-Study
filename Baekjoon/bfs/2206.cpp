// 2206번 = 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <tuple>
#define INF 1000001

using namespace std;
typedef tuple<int, int, int> tp;

int N, M, curY, curX, nextY, nextX, breakFlag;
int res1, res2;

// Keypoint
// 벽을 부신 케이스와 아닌 케이스에 대한 배열을 다르게 정의하여 독립적으로 적용
int map[1000][1000], distMap[1000][1000][2];
char ch;


int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0,-1, 1};
queue<tp> q;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }
    distMap[0][0][0] = 1; // 초기 이동 거리 1로 초기화
    q.push(tp(0, 0, 0)); // position과 breakFlag를 초기값으로 전달

    while(!q.empty()) {
        curY = get<0>(q.front()); curX = get<1>(q.front()); breakFlag = get<2>(q.front());
        q.pop();
        for(int i = 0; i < 4; ++i) { // bfs 로 탐색
            nextY = curY + dy[i]; nextX = curX + dx[i];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue; // seg fault 방지
            if(distMap[nextY][nextX][breakFlag]) continue; // 벽 부수기 + 방문 여부 확인
            else {
                if(map[nextY][nextX] == 1) {
                    if(!breakFlag) {
                        distMap[nextY][nextX][1] = distMap[curY][curX][0] + 1;
                        q.push(tp(nextY,nextX, 1));
                    }
                } else {
                    distMap[nextY][nextX][breakFlag] = distMap[curY][curX][breakFlag] + 1;
                    q.push(tp(nextY,nextX,breakFlag));
                }
            }
        }
    }
    res1 = distMap[N-1][M-1][0] ? distMap[N-1][M-1][0] : INF;
    res2 = distMap[N-1][M-1][1] ? distMap[N-1][M-1][1] : INF;
    if((res1 == INF) && (res2 == INF)) cout << -1 << '\n';
    else {
        cout << min(res1, res2) << '\n';
    }

    return 0;

}