// 5582번 = 공통 부분 문자열

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[4001][4001];
string s1, s2;
int s1_len, s2_len, res;

// 1. dp 정의 - dp[i][j] = s1의 i 번째 글자와 s2 의 j 번째 글자까지의 최대 길이 
// 2. 관계식 - dp[i][j] = dp[i-1][j-1] + 1
// 3. 기저 - i 번째랑 j 번째 같으면 1 아니면 0 

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s1, s2;

    cin >> s1 >> s2;

    s1_len = s1.size(); s2_len = s2.size();
    
    for(int i = 1; i <= s1_len; ++i) {
        for(int j = 1; j <= s2_len; ++j) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = 0;
            res = max(dp[i][j], res);
        }
    }

    cout << res << '\n';

    return 0;
}
