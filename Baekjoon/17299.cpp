// 백준 17299번 = 오등큰수

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[1000001];
int N;

vector<int> v, ngf;
stack<int> st;
int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);
    ngf.resize(N);

    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        arr[v[i]]++;
    }

    for(int i = 0; i < N; ++i) {
        
        while(!st.empty() && arr[v[i]] > arr[v[st.top()]]) {
            ngf[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) {
        ngf[st.top()] = -1; st.pop();
    }

    for(int val: ngf) cout << val << " ";
    cout << '\n';

    return 0;
}