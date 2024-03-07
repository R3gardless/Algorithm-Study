// 11266번 = 단절점

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX 111111

using namespace std;

int V,E, dfsnCnt; // 생성된 dfsn 수를 전역변수로 갖고 감
vector<int> adj[MAX + 2];

int dfsn[MAX + 2]; // 각 노드의 방문 번호
set<int> ans;
int DFS(int curr, bool isRoot) {
    dfsn[curr] = dfsnCnt;
    dfsnCnt++;
    
    int ret = dfsn[curr]; // 올라갈 수 있는 최소 dfsn
    // 자식 '트리' 수
    int childTreeCount = 0;
    for(auto child : adj[curr]) {
        if(dfsn[child] != 0) // 이미 방문 완료한 경우
            ret = min(ret, dfsn[child]);

        else { // 아직 방문 안된 경우 : 새로운 자식 컴포넌트를 탐색 하게 되는 경우
            childTreeCount++;
            int Ctree = DFS(child, false); // Ctree : 자식을 통해 갈 수 있는 최소 번호
            
            if (Ctree >= dfsn[curr] && !isRoot) // 자신이 root가 아니고, 자식트리가 자신 위로 가지 못하면
                ans.insert(curr);

            ret = min(ret, Ctree); // 올라갈 수 있는 최소 번호 업데이트
        }
    }
    // 자신이 root 고 자식트리가 2개 이상이면
    if(isRoot && childTreeCount >= 2) ans.insert(curr);

    return ret;
}

int main() {
    cin >> V >> E;
    for(int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsnCnt = 1;
    for(int i = 1; i <= V; ++i) {
        // isRoot=true : 1은 root
        if(dfsn[i] == 0) DFS(i, true);
    }
    cout << ans.size() << '\n';
    for (auto ss: ans) cout << ss << ' ';

    return 0;
}