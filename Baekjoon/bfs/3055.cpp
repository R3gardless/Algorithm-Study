// 3055번 = 탈출

#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1000

using namespace std;
typedef long long ll;

int R, C, curY, curX, nextY, nextX, destY, destX, cost;
char map[50][50];
int waterMap[50][50], hodgeMap[50][50];
bool waterVisited[50][50], hodgeVisited[50][50];
int dy[4] = {-1 ,1 ,0, 0}, dx[4] = {0, 0, 1, -1};

queue<pair<int, int> > waterQ, hodgeQ;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        fill(waterMap[i], waterMap[i] + C, INF);
        fill(hodgeMap[i], hodgeMap[i] + C, -1);
    }

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> map[i][j];
            if(map[i][j] == '*') {
                waterMap[i][j] = 0;
                waterQ.push(make_pair(i, j));
            } else if(map[i][j] == 'S') {
                hodgeMap[i][j] = 0;
                hodgeQ.push(make_pair(i, j));
            } else if(map[i][j] == 'D') {
                destY = i; destX = j;
            }
        }
    }

    while(!waterQ.empty()) {
        pair<int, int> now = waterQ.front(); waterQ.pop();
        curY = now.first; curX = now.second; cost = waterMap[curY][curX];
        for(int i = 0; i < 4; ++i) {
            nextY = curY + dy[i];
            nextX = curX + dx[i];
            if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
            else if(map[nextY][nextX] != '.' || waterVisited[nextY][nextX]) continue;
            else {
                waterVisited[nextY][nextX] = true;
                waterMap[nextY][nextX] = cost + 1;
                waterQ.push(make_pair(nextY, nextX));
            }
        }
    }

    while(!hodgeQ.empty()) {
        pair<int, int> now = hodgeQ.front(); hodgeQ.pop();
        curY = now.first; curX = now.second; cost = hodgeMap[curY][curX];
        for(int i = 0; i < 4; ++i) {
            nextY = curY + dy[i];
            nextX = curX + dx[i];
            if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;
            else if(hodgeVisited[nextY][nextX] || (cost + 1) >= waterMap[nextY][nextX]) continue;
            else if(map[nextY][nextX] == '.' || map[nextY][nextX] == 'D') {
                hodgeVisited[nextY][nextX] = true;
                hodgeMap[nextY][nextX] = cost + 1;
                hodgeQ.push(make_pair(nextY, nextX));
            }
        }
    }

    // for(int i = 0; i < R; ++i) {
    //     for(int j = 0; j < C; ++j) {
    //         cout << hodgeMap[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    if(hodgeMap[destY][destX] == -1) cout << "KAKTUS" << '\n';
    else cout << hodgeMap[destY][destX] << '\n';

    return 0;

}