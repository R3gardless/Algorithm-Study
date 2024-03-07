// 백준 2346 = 풍선 터뜨리기

#include <iostream>
#include <deque>
#include <utility>

using namespace std;

deque<pair<int, int>> dq;

int N, n, tmp;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> n;
        dq.push_back({i + 1, n});
    }

    int move_cnt = 0;
    for(int i = 0; i < N; ++i) {
        while(move_cnt) {
            if(move_cnt > 0) {
                dq.push_back(dq.front()); dq.pop_front();
                move_cnt--;
            } 
            else {
                dq.push_front(dq.back()); dq.pop_back();
                move_cnt++;
            }
        }
        move_cnt = dq.front().second;
        
        if(move_cnt > 0) move_cnt--; // move_cnt > 0 인 경우, pop 으로 인해 1 감소 시켜줘야 함
                                     // move_cnt < 0 인 경우, 상관 없음   
        
        cout << dq.front().first << " "; 
        dq.pop_front();
    }

}