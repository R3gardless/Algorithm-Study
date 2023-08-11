// 1238번 = 파티

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 123456789

// 첫번째 시도(오답) - A -> X = A번 만큼 다익스트라해서 구해보자 => 시간 초과
// 두번째 시도(정답) - A -> X = 이전의 그래프 방향을 반대로 뒤집어서 X를 시작점으로 다익스트라 쓰면 됨.

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

struct compare {
    bool operator() (const Edge & e1, const Edge & e2) {
        return e1.cost < e2.cost;
    }
};

int N, M, X;
int S, E, W;
int ans;
int dist[1001], dist_ans[1001];
vector<Edge> adjList[1001], reverse_adjList[1001];
priority_queue<Edge, vector<Edge>, compare> pq;

void dijkstra(vector<Edge> adjList[]) {

    pq.push(Edge(X, 0));
    dist[X] = 0;

    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();

        if(cur.cost > dist[cur.to]) continue;

        for(Edge next : adjList[cur.to]) {
            if(dist[next.to] > dist[cur.to] + next.cost) {
                dist[next.to] = dist[cur.to] + next.cost;
                pq.push(Edge(next.to, dist[next.to]));
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> X;

    fill(dist, dist + 1001, INF);

    for(int i = 0; i < M; ++i) {
        cin >> S >> E >> W;
        adjList[S].push_back(Edge(E, W));
        reverse_adjList[E].push_back(Edge(S, W));
    }

    dijkstra(adjList);
    for(int i = 1; i <= N; ++i) dist_ans[i] = dist[i];

    fill(dist, dist + 1001, INF);
    dijkstra(reverse_adjList);
    for(int i = 1; i <= N; ++i) {
        dist_ans[i] += dist[i];
        ans = max(ans, dist_ans[i]);
    }

    cout << ans << '\n';

    return 0;

}