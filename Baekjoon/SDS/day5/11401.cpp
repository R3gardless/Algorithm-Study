// 11401번 = 이항 계수 3

#include <iostream>
#define MAX 4000000
#define MOD 1000000007

typedef long long ll;

using namespace std;

int N, K;

// 페르마 소정리를 이용한 제곱을 빠르게 해결할 수 있음

// MOD 가 소수 이므로 (K!)^MOD-1 = 1 (mod MOD), (K!) ^ (MOD - 2) 은 k! 의 역원
// (k!) ^ (MOD - 2) 구하기
ll Inversion() {
    ll ret = 1LL;
    ll temp = 1LL;
    ll want = MOD - 2;
    // temp = (K!)^1 = (K!)^(2^0)
    for(int i = 2; i <= K; ++i) {
        temp *= i;
        temp %= MOD;
    }
    // MOD - 2 를 이진법으로 계산해서 (K!) ^ (MOD - 2) 계산
    while(want) {
        if(want % 2) {
            ret *= temp;
            ret %= MOD;
        }
        // (k!) ^ (2^i) -> (k!)^(2^(i+1))
        temp *= temp;
        temp %= MOD;
        want /= 2;
    }
    return ret % MOD;
}

ll Combi() {
    ll ret = 1LL;
    for(int i = N; i > N - K; --i) {
        ret *= i;
        ret %= MOD;
    }
    return ret % MOD;
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    ll a = Inversion();
    ll b = Combi();
    cout << (a * b) % MOD << '\n';

    return 0;
}