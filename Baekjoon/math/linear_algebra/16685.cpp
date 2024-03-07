// 16685번 = XOR 포커 (unsolved)

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll; // 2^60 ~ 10^18

int N, cnt;
ll basis[61], num, res, ans;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> num;
        for(int j = 60; j >= 0; --j) {
            if((num >> j) & 1) {
                if(!basis[j]) {
                    basis[j] = num; // leading variable 저장
                    break;
                } else {
                    num ^= basis[j];
                }
            }
        }
    }

    for(int i = 60; i >= 0; --i) {
        if(res < (res ^ basis[i])) {
            cnt++; res = (res ^ basis[i]);
            if(cnt % 2 == 0) ans = max(res, ans);
        }
    }

    cout << ans << '\n';

    return 0;
}