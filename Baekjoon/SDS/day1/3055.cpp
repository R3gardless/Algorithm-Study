// 3055번 = 탈출

// BFS 사용해서 확인

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int map[50][50];
int water_map[50][50];
int R, C;
pair<int, int> start_point, dest_point, water_point;

queue<pair<int, int>> q;


void bfs() {

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> map[i][j];
            if(map[i][j] == '*') {
                water_point.first = i;
                water_point.second = j;
            } else if(map[i][j] == 'D') {
                dest_point.first = i;
                dest_point.second = j;
            } else if(map[i][j] == 'S') {
                start_point.first = i;
                start_point.second = j;
            }
        }
    }


    return 0;

}