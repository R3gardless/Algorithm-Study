#include <iostream>
#include <vector>

using namespace std;

int N, T, q;

vector<int> v;

bool linearSearch(int k) {
 
    int i = 0;
    v[N] = k; // 센티넬 설치로 for 문 사용 방지 → 실행속도 개선

    while(v[i] != k) i++;
    
    return i != N;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N + 1); // 센티넬 설치

    for(int i = 0; i < N; ++i) cin >> v[i];

    cin >> T;

    int cnt = 0;

    while(T--) {
        cin >> q;
        if(linearSearch(q)) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}