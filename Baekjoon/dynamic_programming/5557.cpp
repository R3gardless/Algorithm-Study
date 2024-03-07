// 5557번 = 1학년

#include <iostream>

using namespace std;

typedef long long ll;

int N, arr[111]; // +, - 개수 각각 DP 로 저장
ll dp[111][22];

// 1. 정의 = dp[i][x] : (1 ~ i) 로 x 값을 만드는 경우의 수 (조건 0 <= x <= 20)
// arr[1], arr[2], ..., arr[i] = x 를 만족하는 경우의 수
// dp[N][arr[N]] = 1 ~  N-1 으로 arr[N] 만드는 경우의 수
// i = input 배열 index
// arr[1], arr[2], ..., arr[N-1] = arr[N]
// 2. 관계식 = dp[i][x] = dp[i-1]
// 3. 기저(초기값) = dp[1][arr[1]] = 1

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];

    dp[1][arr[1]] = 1;
    for(int i = 2; i < N; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if(j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
            if(j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
        }
    }

    cout << dp[N - 1][arr[N]] << '\n';

    return 0; 
}