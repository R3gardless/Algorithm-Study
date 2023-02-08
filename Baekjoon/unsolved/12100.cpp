// 백준 12100번 = 2048 (Easy)

#include <iostream>
#include <Vec
using namespace std;

int N;
int board[20][20];
int tep_board[20][20];
int ans = -1;

int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int zero_x[4];
int zero_y[4];


void move(int depth) {
    if(depth == 5) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(board[i][j] > ans) ans = board[i][j];
            }
        }
        return;
    }
    else {
        for(int i = 0; i < 4; ++i) {
            int x_dir = move_x[i];
            int y_dir = move_y[i];
            
            for(int r = 0; r < N; ++r) { // 0 어케 집어넣을꺼임???????????
                for(int c = 0; c < N; ++c) {
                    if(c + x_dir >= N || c + x_dir < 0 || r + y_dir < 0 || r + y_dir < 0) continue;
                    else if(board[r + y_dir][c + x_dir] != board[r][c]) continue;
                    else {
                        if(zero_y[i] == r || zero_x[i] == c) board[r][c] = 0;
                        else {
                            board[r + y_dir][c + x_dir];
                        }
                    }   
                }
            }
            move(depth + 1);
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) cin >> board[i][j];
    }

    zero_x[0] = N-1; zero_x[1] = 0; zero_x[2] = -1; zero_x[3] = -1;
    zero_y[0] = -1; zero_y[1] = -1; zero_y[2] = N-1; zero_y[3] = 0;

    move(0);

    cout << ans << '\n';

    return 0;
}