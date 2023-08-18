// 1516번 = 게임 개발

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, T, pre, next;
int indegree[501]; // indegree[i] = i의 indegree (i 이전 node 개수)
int cost[501]; // cost[i] = i번째 건물 짓는 코스트
vector<int> arr[501]; // arr[i] = i 이후의 건물
queue<int> q;


int ans[501];

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i) {

        cin >> T;
        cost[i] = T;
        cin >> pre;
        while(pre != -1) {
            arr[pre].push_back(i);
            indegree[i]++;
            cin >> pre;
        }
    }

    for(int i = 1; i <= N; ++i) {
        if(indegree[i] == 0) { 
            ans[i] = cost[i]; // indegree 0 인 건물 cost
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        int nowCost = ans[now]; // 현재 node 까지의 cost
        for(int next : arr[now]) {
            indegree[next]--;
            ans[next] = max(ans[next], nowCost + cost[next]);
            if(indegree[next] == 0) q.push(next);
        }
    }

    for(int i = 1; i <= N; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;

}