// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_D

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> st1;
stack<pair<int, int>> st2;
vector<int> res;
string str;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    char ch;

    int sum = 0, size;

    cin >> str;

    for(int i = 0; i < str.size(); ++i) {
        ch = str[i];
        if(ch == '\\') st1.push(i);
        else if(ch == '/' && st1.size() > 0) {
            int j = st1.top(); st1.pop();
            size = i - j;
            sum += size;
            while(st2.size() > 0 && st2.top().first > j) {
                size += st2.top().second; st2.pop();
            }
            st2.push({j, size});
        }
    }

    while(!st2.empty()) {
        res.push_back(st2.top().second);
        st2.pop();
    }

    reverse(res.begin(), res.end());

    cout << sum << '\n';
    cout << res.size();
    for(int val: res) cout << " " << val;
    cout << '\n';

    return 0;
}