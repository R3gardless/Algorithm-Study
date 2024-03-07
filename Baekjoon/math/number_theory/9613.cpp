// 9613번 = GCD 합

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll t, n, sum;
vector<int> vec;

ll gcd(ll a, ll b) { // 유클리드 호제법 구현
    return b ? gcd(b, a % b) : a;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--) {
        cin >> n;
        vec.assign(n, 0);
        sum = 0;
        for(int i = 0; i < n; ++i) cin >> vec[i];
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                sum += gcd(vec[i], vec[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}