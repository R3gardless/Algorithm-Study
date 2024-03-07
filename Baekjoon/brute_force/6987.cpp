// 백준 6987번 = 월드컵

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int match_input[6][3];
int match_result[6][3];
int answer[4];

vector<pair<int, int>> round_info;


void check_match(int tc, int round) {
    if(round == 15) {
        if(answer[tc]) return;
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(match_input[i][j] != match_result[i][j]) return; 
            }
        }

        answer[tc] = 1;

        return;
    }
    else {
        int t1 = round_info[round].first;
        int t2 = round_info[round].second;

        match_result[t1][0]++; match_result[t2][2]++;
        check_match(tc, round + 1);
        match_result[t1][0]--; match_result[t2][2]--;

        match_result[t1][1]++; match_result[t2][1]++;
        check_match(tc, round + 1);
        match_result[t1][1]--; match_result[t2][1]--;

        match_result[t1][2]++; match_result[t2][0]++;
        check_match(tc, round + 1);
        match_result[t1][2]--; match_result[t2][0]--;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 6; ++i) {
        for(int j = i + 1; j < 6; ++j) round_info.push_back({i, j});
    }

    for(int tc = 0; tc < 4; ++tc) {
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 3; ++j) cin >> match_input[i][j];
        }

        check_match(tc, 0);

    }

    for(int val: answer) cout << val << ' ';
    cout << '\n';
    return 0;

}