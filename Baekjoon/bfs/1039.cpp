// 백준 1039번 = 교환

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string N;
int K, len, res;
bool visited[1000001];
queue<pair<string, int> > q;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    len = N.size(); res = -1;
    q.push(make_pair(N, 1));

    while(!q.empty()) {
        string now = q.front().first; int curK = q.front().second; q.pop();
        if(curK > K) continue;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(i == 0 && N[j] == '0') continue;
                else {
                    string next = now;
                    char ch = next[j];
                    next[j] = next[i];
                    next[i] = ch;
                    if((K - curK) % 2 == 0) res = max(res, stoi(next));
                    if(!visited[stoi(next)]) {
                        visited[stoi(next)] = true;
                        q.push(make_pair(next, curK + 1));
                    }
                }
            }
        }
    }
    
    cout << res << '\n';

    return 0;

}