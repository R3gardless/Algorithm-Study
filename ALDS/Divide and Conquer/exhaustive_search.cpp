#include <iostream>
#include <vector>

using namespace std;

int n, q, s;

vector<int> v;

int solve(int i, int m) {
    if(m == 0) return 1;
    if(i >= n) return 0;
    int res = solve(i + 1, m) || solve(i + 1, m - v[i]);
    return res;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    v.resize(n);

    for(int i = 0; i < n; ++i) cin >> v[i];

    cin >> q;

    for(int i = 0; i < q; ++i) {
        cin >> s;
        if(solve(0, s)) cout << "yes\n";
        else cout << "no\n";
    } 

    return 0;
    
}