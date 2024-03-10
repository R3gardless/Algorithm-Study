// 1368번 = 물대기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 301;

int N, M;
vector<pair<int, int>> arr[MAX]; // arr[a] = (b , c) -> Node a 에 연결 (Node b, Weight c) 
bool visited[MAX]; // visited[x] = component 에 x 노드 포함여부 확인
int cnt, ans, w;

struct cmp {
    bool operator()(pii a, pii b) {
        return a.second > b.second; // 내림차순 정렬
    };
};
priority_queue<pii, vector<pii>, cmp> pq;

int main() {
    cin >> N;

    // 우물은 0번 노드 고정
    for(int b = 1; b <= N; ++b) {
        cin >> w;
        arr[0].push_back({b, w});
    }

    pq.push(pii(0, 0));
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> w;
            if(i >= j) continue;
            arr[j].push_back({i, w});
        }
    }

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