// 백준 9436번 = Round Robin

#include <iostream>
#include <queue>

using namespace std;

int N, T, p, c;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    while(N) {
        cin >> T;

        bool end_flag = false;

        queue<int> q;

        for(int i = 0; i < N; ++i) q.push(0);

        while(!end_flag){
            end_flag = true;
            for(int i = 0; i < T - 1; ++i) {
                c = q.front(); q.pop();
                q.push(c+1);
            }
            q.pop(); N--;

            for(int i = 0; i < N; ++i) {
                int temp = q.front(); q.pop(); q.push(temp);
                if(temp != q.front()) end_flag = false;
            }

        }

        cout << N << ' ' << c+1 << '\n';

        cin >> N;
    }
}