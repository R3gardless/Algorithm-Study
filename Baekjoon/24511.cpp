// 백준 24511번 = queuestack

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int N, M, cnt, tmp;
vector<int> v_type;
stack<int> st;
queue<int> qu;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v_type.resize(N);
 
    for(int i = 0; i < N; ++i) cin >> v_type[i];

    for(int i = 0; i < N; ++i) {
        cin >> tmp;
        if(v_type[i]) continue;
        else {
            st.push(tmp);
            cnt++;
        }
    }

    cin >> M;

    for(int i = 0; i < M; ++i) {
        cin >> tmp;
        if(i < M - cnt) qu.push(tmp);
    }

    while(!st.empty() && M) {
        cout << st.top() << ' '; st.pop();
        M--;
    }

    while(!qu.empty()) {
        cout << qu.front() << ' '; qu.pop();
    }

    return 0;
}