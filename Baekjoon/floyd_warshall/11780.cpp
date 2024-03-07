// 11780번 = 플로이드 2

#include <iostream>
#include <algorithm>
#define INF 9876543210

typedef long long ll;
using namespace std;

ll dist[101][101];
int mov_cnt[101][101];
int mov_path[101][101];
int N, M;
ll A, B, C;

void floydwarshall() {

    for(int k = 1; k <= N; ++k) { // 경유
        for(int i = 1; i <= N; ++i) { // start
            for(int j = 1; j <= N; ++j) { // dest
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    mov_cnt[i][j] = (mov_cnt[i][k] + mov_cnt[k][j]);
                    dist[i][j] = dist[i][k] + dist[k][j];
                    mov_path[i][j] = k;
                } 
            }
        }
    }
}

void printPath(int start, int dest) {

    if(start == dest) {
        cout << start << " ";
        return;
    } else {
        int pass = mov_path[start][dest];
        if(pass != dest) {
            printPath(start, pass);
            printPath(pass, dest);
        } else printPath(pass, dest);
    }

}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i == j) dist[i][j] = 0;
            else {
                dist[i][j] = INF;
                mov_path[i][j] = j;
                mov_cnt[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < M; ++i) {
        cin >> A >> B >> C;
        dist[A][B] = min(dist[A][B], C);
    }


    floydwarshall();

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(dist[i][j] == INF) dist[i][j] = 0;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(dist[i][j] == INF || i == j) cout << "0\n";
            else {
                cout << mov_cnt[i][j] + 1 << " " << i << " ";
                printPath(i, j);
                cout << '\n';
            }
        }
    }

    return 0;

}