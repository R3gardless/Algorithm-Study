// 1463번 = 1로 만들기

#include<iostream>
#include<algorithm>
#define INF 1000001

using namespace std;

int dp[1000001];
int N;

// 1. dp 정의 - dp[i] i가 만들어질 수 있는 연산 최솟값
// 2. 점화식 - 코드 참고 
// 3. 기저 - dp[1] = 0, dp[2] = 1, dp[3] = 1

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[1] = 0; dp[2] = 1; dp[3] = 1;

    cin >> N;

    for(int i = 4; i <= N; ++i) {
        dp[i] = dp[i-1];
        dp[i] = i % 3 ? dp[i] : min(dp[i], dp[i/3]);
        dp[i] = i % 2 ? dp[i] : min(dp[i], dp[i/2]);
        
        dp[i]++;
    }

    cout << dp[N] << '\n';

    return 0;
}