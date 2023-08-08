// 3860번 = 할로윈 묘지
#include <iostream>
#include <queue>
#include <vector>
#define INF 9876543210

typedef long long ll;
using namespace std;

struct Point {
    int y;
    int x;
    Point(int y1, int x1) : y(y1), x(x1) {}
};

struct Edge {
    Point from;
    Point to;
    int cost;
    Edge(Point p1, Point p2, int cost1) : from(p1), to(p2), cost(cost1) {}
};

int W, H, G;
int X, Y;
int E, X1, X2, Y1, Y2, T;
bool isCycle;
int map[30][30];
ll dist[30][30];
vector<Edge> edgeList;


void bellmanFord() {
    dist[0][0] = 0;
    // 1. (정점의 개수 - 1) 번 만큼 간선을 확인
    for(int i = 1; i < W * H; ++i) { // N - 1 탐색 사이클 횟수
        for(Edge next : edgeList) {
            Point from = next.from; // 이전 정점 (x, y) 좌표
            Point to = next.to; // 다음 정점 (x, y) 좌표
            if(dist[to.y][to.x] > dist[from.y][from.x] + next.cost && dist[from.y][from.x] != INF) {
                dist[to.y][to.x] = dist[from.y][from.x] + next.cost; // 특정 정점을 경유해서 지나가는 비용이 더 작으면 업데이트
            }
        }
    }
    // 2. 간선을 모두 확인하는 사이클을 한 번 더 수행하며 음수 사이클 확인
    for(int i = 1; i < W * H; ++i) { // N - 1 탐색 사이클 횟수
        for(Edge next : edgeList) {
            Point from = next.from; // 이전 정점 (x, y) 좌표
            Point to = next.to; // 다음 정점 (x, y) 좌표
            if(dist[to.y][to.x] > dist[from.y][from.x] + next.cost && dist[from.y][from.x] != INF) {
                isCycle = true;
                return;
            }
        }
    }
}

// 1. 잔디가 있는 칸으로 자유롭게 이동 가능 (동서남북 인접한 칸) -> 인접한 정점 사이에는 비용 1인 간선 존재
// 2. 묘비 있는 칸으로 이동 X -> 간선 사용 X
// 3. 구멍이 있는 칸으로 갈 경우 특정 시간 이후에 특정 지점으로 나타남 -> 기준 정점에서 특정 정점까지 비용 t 존재


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cin >> W >> H;
        if(W == 0 && H == 0) break;

        cin >> G;

        for(int i = 0; i < G; ++i) {
            cin >> X >> Y;
            map[Y][X] = 1; // 묘비는 1로 표시
        }

        cin >> E;

        for(int i = 0; i < E; ++i) {
            cin >> X1 >> Y1 >> X2 >> Y2 >> T;

            map[Y1][X1] = 2; // 구멍은 2로 표시
            edgeList.push_back(Edge(Point(Y1,X1), Point(Y2, X2) , T)); // 구멍타고 가는 간선 정보 저장
        }

        // 가능한 모든 간선 정보 추가
        int y_dir[4] = {-1, 1, 0, 0};
        int x_dir[4] = {0, 0, -1, 1};
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                // 묘비나 구멍이면 간선 탐색 생략
                // 최종 도착지일 경우 간선 탐색 생략
                if(map[i][j] != 0 || (i == H-1 && j == W-1)) continue;
                for(int k = 0; k <= 3; ++k) {
                    int r = i + y_dir[k];
                    int c = j + x_dir[k];
                    if(r >= 0 && r < H && c >= 0 && c < W && map[r][c] != 1) {
                        edgeList.push_back(Edge(Point(i,j), Point(r,c) ,1));
                    }
                }
            }
        }

        // dist 배열 초기화
        for(int i = 0; i < H; ++i) {
            fill(dist[i], dist[i] + 30, INF);
        }

        bellmanFord();

        if(isCycle) cout << "Never\n";
        else {
            if(dist[H-1][W-1] == INF) {
                cout << "Impossible\n";
            } else cout << dist[H-1][W-1] << "\n";
        }
    }

}