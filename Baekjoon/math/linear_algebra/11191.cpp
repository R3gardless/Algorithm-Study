// 11191번 = Xor Maximization

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll; // 10^18 ~ 2^60
int N;
ll num, res, basis[61];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> num; 
        for(int j = 60; j >= 0; --j) {
            if((num >> j) & 1) {
                if(!basis[j]) { // 해당 leading variable 존재하지 않는 경우
                    basis[j] = num;
                    break;
                } else { // 해당 leading variable 존재하는 경우
                    num ^= basis[j]; // 해당 leading variable row 와 xor 연산 후 진행
                }
            }
        }
    }

    for(int i = 60; i >= 0; --i) {
        res = max(res, res ^ basis[i]);
    }

    cout << res << '\n';

    return 0;

}