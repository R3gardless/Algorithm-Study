// 백준 1920번 = 수 찾기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int N, M, k;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cin >> M;

    while(M--) {
        cin >> k;
        if(binary_search(v.begin(), v.end(), k)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    
    return 0;
}