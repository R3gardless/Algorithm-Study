// 2252번 = 줄 세우기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 33333;

int N, M;
vector<int> arr[MAX];
// indegree[i]: i 학생 앞에 와야 하는 학생 수
int indegree[MAX];
queue<int> myQueue;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int next, pre;
        cin >> pre >> next;
        // 뒤 학생의 indgree++
        indegree[next] += 1;
        // 앞 학생의 자식 추가
        arr[pre].push_back(next);
    }
    for (int i = 1; i <= N; ++i) {
        // 자신의 앞에 올 학생이 없는 학생 선별
        if (indegree[i] == 0)
            myQueue.push(i);
    }
    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();
        ans.push_back(now);
        for (auto iter : arr[now]) {
            indegree[iter]--;
            // now 자식들 중 now 가 빠지면서 indegree=0 이 되는 학생 선별
            if (indegree[iter] == 0) myQueue.push(iter);
        }
    }
    for (int i = 0; i < N; ++i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}