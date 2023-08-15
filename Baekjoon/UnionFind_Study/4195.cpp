// 4195번 = 친구 네트워크

#include <iostream>
#include <map>
#include <string>

using namespace std;

int TC, N;
map<string, int> m;
string s1, s2;
int p[200000];

int find(int n) {
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void union_(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> TC;

    while(TC--) {
        cin >> N;
        fill(p, p + N * 2, -1);
        m.clear();
        for(int i = 0; i < N; ++i) {
            cin >> s1 >> s2;
            if(m.find(s1) == m.end()) m.insert({s1, m.size()});
            if(m.find(s2) == m.end()) m.insert({s2, m.size()});
            union_(m[s1], m[s2]);    
            cout << -p[find(m[s1])] << '\n';
        }
    }

    return 0;

}
