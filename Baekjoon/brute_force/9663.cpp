// 9663번 = N-Queen

#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
bool flag;
vector<int> board; // index = board 열
                   // value = 해당 열에 들어가는 queen 의 행 위치

void backtracking(int depth) {
    if(depth == N) {
        cnt++;
        return;
    } else {
        for(int i = 1; i <= N; ++i) {  // 1부터 N까지의 위치에 배치 가능
            flag = false;
            for(int j = 0; j < depth; ++j) { // 현재까지 놓여진 위치까지 탐색을 하면서 못 놓는 위치 확인
                // 해당 행에 이미 놓여져 있거나 대각선 위치에 존재하는 퀸이 있다면 무시
                if(board[j] == i || (depth - j) == abs(i - board[j])) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                board[depth] = i;
                backtracking(depth + 1);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    board.assign(N, 0);

    backtracking(0);

    cout << cnt << '\n';

    return 0;

}