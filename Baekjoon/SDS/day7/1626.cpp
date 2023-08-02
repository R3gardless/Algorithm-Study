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
        parent
    }
}
