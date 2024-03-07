// 1256번 = 사전

#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#define INF 1000000001
#define MAX 101
using namespace std;
int N, M, K;

int dp[MAX][MAX]; // a => M개, z => N개 일 때 경우의 수 (index)
// 관계식 dp[m-1][n] + dp[m][n-1] 
// (n+m)! / n!m!
// 기저 m = 0 => z만 N개, n = 0 => a만 M개 

int getDP(int A, int Z) {

    // 기저일 시 return 1
    if(A == 0 || Z == 0) return 1;

    int& ret = dp[A][Z];
    // 한 번 돌아서 그 값을 안다면 값 리턴
    if(ret != -1) return ret;

    // dp[x][y] = dp[x-1][y] + dp[x][y-1]
    ret = min(getDP(A - 1, Z) + getDP(A, Z - 1), INF);
    return ret;
}
// 정답이 될 단어 만들기
// a 개수, z 개수, 이전 순번
string getWord(int A, int Z, int order) {
    string ret = "";

    if(A == 0) {
        for(int i = 0; i < Z; ++i) ret += 'z';
        return ret;
    } 
    if (Z == 0) {
        for (int i = 0; i < A; ++i) ret += 'a';
        return ret;
    }
    // a가 맨앞에 붙고 나머지 a-1, z로 만들 수 있는 경우의 수
    int aFrontCnt = getDP(A - 1, Z);
    // 맨 앞에 a를 붙이는 경우
    if (order <= aFrontCnt) {
        ret = 'a' + getWord(A - 1, Z, order);
    }
    // 맨 앞에 z를 붙이는 경우
    else {
        ret = 'z' + getWord(A, Z - 1, order - aFrontCnt);
    }
    return ret;
}



int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> K;

    if(K > getDP(N, M)) cout << -1 << '\n';
    else cout << getWord(N, M, K) << '\n';

    return 0;
}