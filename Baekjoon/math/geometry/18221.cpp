// 18221번 = 교수님 저는 취업할래요

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N, cnt, diffX, diffY;
int map[1000][1000];
pair<int, int> pos_prof, pos_me, start, dest;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 5) pos_prof = make_pair(i, j);
            else if(map[i][j] == 2) pos_me = make_pair(i, j);
        }
    }

    start = make_pair(min(pos_prof.first, pos_me.first), min(pos_prof.second, pos_me.second));
    dest = make_pair(max(pos_prof.first, pos_me.first), max(pos_prof.second, pos_me.second));

    diffX = dest.first - start.first;
    diffY = dest.second - start.second;

    if(diffY * diffY + diffX * diffX < 25) {
        cout << "0\n";
        return 0;
    }

    for(int i = start.first; i <= dest.first; ++i) {
        for(int j = start.second; j <= dest.second; ++j) {
            if(map[i][j] == 1) cnt++;
        }
    }
    // cout << "\n" << start.first << " " << start.second << "\n";
    // cout << dest.first << " " << dest.second << "\n";
    if(cnt >= 3) cout << "1\n";
    else cout << "0\n";

    return 0;

}