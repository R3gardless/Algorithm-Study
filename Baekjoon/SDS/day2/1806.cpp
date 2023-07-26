// 1806번 = 부분합

#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> S;

    vec.assign(N, 0);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    int s = 0, e = 0;
    int sum = 0, res = 987654321;
    bool flag = false;
    while(s <= e) {
        if(e == N || sum > S) sum -= vec[s++];
        else sum += vec[e++];
        
        if(sum >= S) {
            flag = true;
            if((e-s) < res) res = (e-s);
        }
    }
    if(flag) cout << res << '\n';
    else cout << 0 << '\n';
    return 0;
}