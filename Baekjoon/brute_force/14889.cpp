// 14889번 = 스타트와 링크

#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int N, sum;
int diff = INF;
int ability[20][20];
vector<bool> team; // bool 을 사용하여 상대편 점수 합산 가능하게 구현

void backtracking(int idx, int depth) {
    if(depth == (N /2)) {
        int start = 0, link = 0;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(team[i] && team[j]) start += ability[i][j];
                else if(!team[i] && !team[j]) link += ability[i][j];
            }
        }
        diff = diff > abs(start - link) ? abs(start - link) : diff;
        return; 
    } else {
        for(int i = idx; i < N; ++i) {
            team[i] = true;
            backtracking(i + 1, depth + 1);
            team[i] = false;
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    team.assign(N, false);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> ability[i][j];
        }
    }

    backtracking(0, 0);

    cout << diff << '\n';

    return 0;

}