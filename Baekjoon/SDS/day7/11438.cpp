#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define V_MAX 100001
#define P_MAX 18 // 2 ^ 17 > 10^5


using namespace std;


int N; // vertex 개수
int T;
vector<int> adj[V_MAX]; // 인접 리스트로 edge 정보 저장 adj[a] = b : a - b 연결
int parent[V_MAX][P_MAX]; // parent[a][k] : a 의 2^k 번째 부모
int depth[V_MAX]; // depth[a] : a 노드의 길이 (루트 깊이는 0)
int u, v;

void MakeTreeDFS(int curr) { // 주어진 정보를 바탕으로 트리를 한 번 그려보면서 각 노드의 depth 와 0번째 부모 생성
    for (int next : adj[curr]) {
        if(depth[next] == -1) {
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            MakeTreeDFS(next);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // parent, depth 초기화
    memset(parent, -1, sizeof(parent));
    memset(depth, -1, sizeof(depth));

    depth[1] = 0; // root 노드의 depth
    MakeTreeDFS(1); // root 노드는 1이라 가정

    // i 의 2^j 번째 부모 k가 있으면, i의 2^j * 2 번째 부모는 k의 2^j 번째 부모
    for(int j = 0; j < P_MAX - 1; ++j) {
        for(int i = 1; i <= N; ++i) {
            int k = parent[i][j];
            if (k != -1) parent[i][j + 1] = parent[k][j];
        }
    }
    cin >> T;
    while(T--) {
        // u, v 의 LCA 구하기
        cin >> u >> v;
        if (depth[u] < depth[v]) swap(u, v); // depth[u] >= depth[v] 로 생각하기 위해 조정
        int diff = depth[u] - depth[v];
        // u 와 v 를 같은 높이로 맞춰주기 (이진법 스킬)
        int j = 0;
        while(diff) {
            if(diff % 2) {
                u = parent[u][j];
            }
            j++;
            diff /= 2;
        }
        // u==v 이면 u ,v 는 공통 조상
        if (u != v) {
            // 2 ^ 17, 2 ^ 16, ... , 2 , 1번째 부모 비교
            // 제일 먼 조상부터 탐색 (중요)
            for(int j = P_MAX - 1; j >= 0; --j) {
                // 2^j 번째 조상이 다른 게 나오면 u, v 를 각각의 2^j 번째 조상으로 변경
                if (parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }  
            // 위 과정 끝나면 최종 u, v 는 같은 부모 아래에 있음
            u = parent[u][0];
        }
        cout << u << '\n';
    }
    

    return 0;

}