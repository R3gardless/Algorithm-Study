// 9252번 = LCS2

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
pair<int, int> res;
int s1_len, s2_len;
string s1, s2;

void printLCS(pair<int, int> p) {
    if(dp[p.first][p.second] == 1) {
        cout << s1[p.first - 1];
        return;
    } else {
        pair<int, int> tmp = make_pair(p.first - 1, p.second - 1);
        printLCS(tmp);
        cout << s1[p.first - 1];
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> s1 >> s2;

    s1_len = s1.size(); s2_len = s2.size();

    for(int i = 1; i <= s1_len; ++i) {
        for(int j = 1; j <= s2_len; ++j) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[s1_len][s2_len] << '\n';
    if(dp[s1_len][s2_len]) {
        string res;
        while(s1_len !=0 && s2_len !=0) {
        if(s1[s1_len - 1] == s2[s2_len - 1]) {
            res = s1[s1_len - 1] + res;
            s1_len--; s2_len--;
        } else if(dp[s1_len][s2_len] == dp[s1_len-1][s2_len]) {
            s1_len--;
        } else if(dp[s1_len][s2_len] == dp[s1_len][s2_len-1]) {
            s2_len--;
        } 
    }

    cout << res << '\n';

    }

    return 0;

}