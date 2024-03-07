// 2293번 = 동전 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, coin, min_coin;
vector<int> coin_vec;
int dp[100001];

// 1. DP 정의 - K원이 될 경우의 수
// 2. 관계식 - dp[x] = dp[x-coin_vec[0]] + dp[x-coin_vec[1]] + dp[x-coin_vec[2]] ... + dp[x-coin_vec[N-1]]  
// 3. 기저 - dp[coin_vec[0]] = 1, dp[coin_vec[1]] = 1 ... dp[coin_vec[N-1]] = 1 

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    coin_vec.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> coin_vec[i];
        dp[coin_vec[i]] = 1;
    }

    sort(coin_vec.begin(), coin_vec.end());

    min_coin = coin_vec[0];

    for(int cost = min_coin + 1; cost <= K ; ++cost) {
        for(int i = 0; i < N; ++i) {
            if(cost - coin_vec[i] < 0) continue;
            else dp[cost] += dp[cost - coin_vec[i]];
        }
    }
    for(int i =  1; i <= K; ++i) cout << dp[i] << ' ';

    return 0;

}