// 1922번 = 네트워크 연결

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1111;

int N, M;
vector<pair<int, int>> arr[MAX]; // arr[a] = (b, c) -> a 에 연결 (Node b, Weight c)
bool visited[MAX]; // visited[x] = 컴포넌트에 x 노드 포함되었는지 여부
int cnt, ans;

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    };
};
priority_queue<pii, vector<pii>, cmp> pq;

int main() {

    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[b].push_back({a, c});
        arr[a].push_back({b, c});
    }

    pq.push(pii(1, 0));

    while(cnt < N) {
        int u = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(visited[u]) continue;

        cnt++;
        ans += cost;
        visited[u] = true;

        for(int i = 0; i < arr[u].size(); ++i) {
            if(visited[arr[u][i].first]) continue;
            pq.push(arr[u][i]);
        }
    }

    cout << ans << '\n';

    return 0;
}