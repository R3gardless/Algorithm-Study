// 16991번 = 외판원 순회 3

#include <iostream>
#include <cmath>
#define INF 123456789

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x1, int y1) : x(x1), y(y1) {};
    Point() : x(0), y(0) {};
};

int N, x, y;
double dp[16][(1 << 16)];
Point map[16];

double dist(Point a, Point b) {

    return sqrt(pow(a.y - b.y , 2) + pow(a.x - b.x , 2));
}

double dfs(int now, int visited) {
    // 모든 도시를 방문 했을 경우
    if(visited == (1 << N) - 1) {
        return dist(map[now], map[0]);
    }

    // 중복 경로 방지 (dp가 업데이트 된 경우)
    if(dp[now][visited] != -1) return dp[now][visited];

    dp[now][visited] = INF;
    for(int i = 0; i < N; ++i) {

        if(i == now || (visited & (1 << i)) != 0) continue;

        dp[now][visited] = min(dp[now][visited], dfs(i, visited | (1 << i)) + dist(map[now], map[i]));
    }

    return dp[now][visited];

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> x >> y;
        map[i] = Point(x, y);
        for(int j = 0; j < (1 << N); ++j) {
            dp[i][j] = -1;
        }
    }

    printf("%.6f\n", dfs(0, 1));

    return 0;
}
