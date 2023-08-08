// 백준 9251번 = LCS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int res;

// 1. dp 정의 - dp[i][j] = string1 i번째, string2 j번째 까지의 LCS
// 2. 관계식 - 같으면 dp[i][j] = dp[i-1][j-1] + 1, 다르면 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// 3. 기저 - dp[i][0] = 0, dp[0][j] = 0

string s1, s2;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s1 >> s2;

    for(int i = 1; i <= s1.size(); ++i) {
        for(int j = 1; j <= s2.size(); ++j) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            res = max(dp[i][j], res);
        }
    }

    cout << res << '\n';

    return 0;
}