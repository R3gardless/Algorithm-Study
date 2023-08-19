// 1806번 = 부분합

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int N, S, s, e;
int ans = 100001;
ll sum = 0;
vector<int> vec;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;

    vec.resize(N);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    while(s <= e) {
        if(e == N || sum > S) sum -= vec[s++];
        else sum += vec[e++];

        if(sum >= S) ans = min(ans, e-s);
    }
    if(ans == 100001) ans = 0;
    cout << ans << '\n';

    return 0;

}