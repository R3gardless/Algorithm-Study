// 백준 15684번 = 사다리 조작

#include <iostream>
#include <vector>

using namespace std;

int N, M, H, a, b;
int ans = 1000000000;
int ladder_map[30][11]; // 1 ~ N - 1 idx 사용z
int depth; // 최적화를 위한 변수

bool check_reach() {
    for(int n = 1; n <= N; ++n) {
        int cur_line = n;
        for(int h = 0; h < H; ++h) {
            if(ladder_map[h][cur_line]) cur_line++;
            else if(ladder_map[h][cur_line-1]) cur_line--;
        }
        if(cur_line != n) return false;
    }
    return true;
}

void search(int row, int cnt) {
    if(cnt == depth) { // 해당 경우에 안 될 경우에는 굳이 선을 추가할 의미가 없으므로 return
        if(check_reach()) {
            ans = min(ans, cnt);
            return;
        }
    }
    else {
        for(int i = row; i < H; ++i) {
            for(int j = 1; j < N; ++j) {
                if(ladder_map[i][j] || ladder_map[i][j-1] || ladder_map[i][j+1]) continue;

                ladder_map[i][j] = 1;
                search(i, cnt + 1);
                ladder_map[i][j] = 0;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;

    for(int i = 0; i < M; ++i) {
        cin >> a >> b;
        ladder_map[a-1][b] = 1;
    }
    
    for(depth = 0; depth < 4; ++depth) {
        search(0, 0);
    }
    
    if(ans > 3) ans = -1;
    
    cout << ans << '\n';

    return 0;
}