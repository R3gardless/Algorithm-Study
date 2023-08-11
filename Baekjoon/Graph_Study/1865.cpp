// 1865번 = 웜홀
// 모든 정점을 시작점으로 잡아야 되므로 임의의 정점(0) 이 다른 모든 정점과 연결되어 있다고 가정한 상태로 시작
#include <iostream>
#include <vector>
#define INF 123456789

typedef long long ll;

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

int TC, N, M, W;
int S, E, T;
bool isCycle;
ll dist[501];
vector<int> hole_start;
vector<Edge> adjList[501];

void bellmanford() {
    dist[0] = 0;
    isCycle = false;

    for(int i = 1; i < N; ++i) {
        for(int j = 0; j <= N; ++j) {
            for(Edge next : adjList[j]) {
                if(dist[next.to] > dist[j] + next.cost && dist[j] != INF) {
                    dist[next.to] = dist[j] + next.cost;
                }
            }
        }
    }
    for(int j = 0; j <= N; ++j) {
        for(Edge next : adjList[j]) {
            if(dist[next.to] > dist[j] + next.cost && dist[j] != INF) {
                isCycle = true;
                return;
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> TC; 

    while(TC--) {
        cin >> N >> M >> W;
        fill(dist, dist + 501, INF); // 초기화
        for(int i = 1; i <= 500; ++i) {
            adjList[0].push_back(Edge(i, 0));
            adjList[i].clear(); // 초기화
        }

        for(int i = 1; i <= M; ++i) {
            cin >> S >> E >> T;
            adjList[S].push_back(Edge(E, T));
            adjList[E].push_back(Edge(S, T));
        }
        for(int i = 1; i <= W; ++i) {
            cin >> S >> E >> T;
            adjList[S].push_back(Edge(E, -T));
            hole_start.push_back(S);
        }
        
        bellmanford();

        if(isCycle) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

