// 1916번 = 최소 비용 구하기

#include <iostream>
#include <vector>
#include <queue>
#define INF 123456789

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1): to(to1), cost(cost1) {}
};

struct compare {
    bool operator() (const Edge & E1, const Edge & E2) {
        return E1.cost < E2.cost;
    }
};

int N, M;
int S, E, W;
int dist[1001];
vector<Edge> adjList[1001];
priority_queue<Edge, vector<Edge>, compare> pq;

void dijkstra() {

    pq.push(Edge(S, 0));
    dist[S] = 0;

    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();

        if(dist[cur.to] < cur.cost) continue;

        for(Edge next: adjList[cur.to]) {
            if(dist[next.to] > dist[cur.to] + next.cost) {
                dist[next.to] = dist[cur.to] + next.cost;
                pq.push(Edge(next.to, dist[next.to]));
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    fill(dist, dist + 1001, INF);

    for(int i = 0; i < M; ++i) {
        cin >> S >> E >> W;
        adjList[S].push_back(Edge(E, W));
    }

    cin >> S >> E;

    dijkstra();

    cout << dist[E] << '\n';

    return 0;
}