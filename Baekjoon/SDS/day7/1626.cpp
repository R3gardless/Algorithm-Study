// 1626번 = 2번째로 작은 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50000 // 2^16 > 50000
#define DMAX 16
#define INF 123456789

using namespace std;

typedef pair<int, int> pii;

int V, E;

struct Edge {
    int A;
    int B;
    int W;
    bool Used = false;
    Edge() : Edge(0, 0, 0) {}
    Edge(int a1, int b1, int w1) : A(a1), B(b1), W(w1) {}
};

vector <Edge> vec; // Edge 저장
bool cmp(const Edge & E1, const Edge & E2) {
    return E1.W < E2.W;
}
// Union Find
int R[MAX + 1]; // R[i] : i의 대표
int Find(int x){
    if(R[x] == 0) return x;
    return R[x] = Find(R[x]);
}

void Union(int x, int y) {
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    R[yRoot] = xRoot;
}

// LCA 를 위한 재료
vector<pii> adj[MAX + 1]; // adj[i] : i 의 자식노드, 해당 가중치
int Depth[MAX + 1];
int parent[MAX + 1][DMAX + 1]; // parent[i][k] = i 의 2^k 조상
// Biggest[i][k] : i의 2^k 조상으로 가능 길에 있는 가장 큰 수, 2번째로 큰 수
// 가장 큰 수로 대체 했을 경우 최소 MST 와 같은 경우 방지
pii Biggest[MAX + 1][DMAX + 1];

void MakeDepth(int curr) {
    for (auto child : adj[curr]) {
        if(Depth[child.first] != 0) continue;
        Depth[child.first] = Depth[curr] + 1;
        parent[child.first][0] = curr;

        // MST 를 구성하는 edge 들의 최대값을 계산하면서 진행
        Biggest[child.first][0] = pii(child.second, - 1);
        MakeDepth(child.first);
    }
}

// 추가할 Edge(a-b) 가 만드는 cycle 을 LCA 를 이용해 찾고 cycle 안에 대체 가능한 가장 큰 수 찾기
int GetPlusByLCA(Edge EE) {
    int x = EE.A;
    int y = EE.B;
    int w = EE.W;
    // 대체 가능한 간선의 가장 큰 가중치, w 와 달라야 한다.
    int ret = -1;
    if (Depth[x] < Depth[y]) swap(x, y);
    int diff = Depth[x] - Depth[y];
    int cnt = 0;
    while(diff) {
        if (diff % 2 == 1) {
            // 경로 중 가장 큰 가중치
            if (Biggest[x][cnt].first != w)
                ret = max(ret, Biggest[x][cnt].first);
            // 경로 중 두번째로 큰 가중치
            else if (Biggest[x][cnt].second != -1)
                ret = max(ret, Biggest[x][cnt].second);
            
            x = parent[x][cnt];
        }
        diff /= 2;
        cnt++;
    }
    if (x != y) {
        
    }
}