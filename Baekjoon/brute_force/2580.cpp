// 2580번 = 스도쿠

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[9][9], N;
bool row_check[9][10], col_check[9][10]; // 행,열에 해당하는 index 를 가진 숫자 존재 여부 확인하는 배열
vector<pair<int, int>> blank_vec;

void backtracking(int depth) {
    if(depth == N) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    } else {
        int y,  x, square_y, square_x;
        vector<bool> check(10, false);
        y = blank_vec[depth].first; x = blank_vec[depth].second;

        square_y = (y / 3) * 3; square_x = (x / 3) * 3;

        for(int i = square_y; i < square_y + 3; ++i) {
            for(int j = square_x; j < square_x + 3; ++j) {
                check[board[i][j]] = true; // 사각형 내에 있는 숫자 확인
            }
        }

        for(int i = 1; i <= 9; ++i) {
            if(check[i] || row_check[y][i] || col_check[x][i]) continue;
            board[y][x] = i;
            row_check[y][i] = true; col_check[x][i] = true;
            backtracking(depth + 1);
            row_check[y][i] = false; col_check[x][i] = false;
        }
        board[y][x] = 0; // 해당 값을 채우지 못하면 비워줘야 됨
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> board[i][j]; 
            if(!board[i][j]) { // 0인 경우
                blank_vec.push_back({i , j});
                N++;
            } else { // 0이 아니라면?
                row_check[i][board[i][j]] = true; // i번째 행에 숫자 check
                col_check[j][board[i][j]] = true; // j번째 열에 숫자 check
            }
        }
    }    

    backtracking(0);

    return 0;
}