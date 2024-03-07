// 백준 17298번 = 오큰수

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> v;
vector<int> nge;
stack<int> st;
int N;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);
    nge.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    for(int i = 0; i < N; ++i) {
        
        while(!st.empty() && v[i] > v[st.top()]) {
            nge[st.top()] = v[i]; st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) {
        nge[st.top()] = -1; st.pop();
    }

    for(int val: nge) cout << val << ' ';
    cout << '\n';
}
