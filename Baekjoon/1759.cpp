// 백준 1759번 = 암호 만들기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<char> v;
vector<char> ans;

void makePassword(int idx, int depth, bool flag, int cnt) {
    if(depth == L && flag && cnt >= 2) {
        for(char ch: ans) cout << ch;
        cout << '\n';
        return;
    }
    for(int i = idx; i < C; ++i) { 
        ans[depth] = v[i];
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') makePassword(i + 1, depth + 1, true, cnt);
        else makePassword(i + 1, depth + 1, flag, cnt + 1);
    }
    return;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> L >> C;

    v.resize(C);
    ans.resize(L);
    
    for(int i = 0; i < C; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    makePassword(0, 0, false, 0);   
}