// 백준 2164번 = 카드 2

#include <iostream>
#include <queue>

using namespace std;

int N;

queue<int> qu;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) qu.push(i+1);

    while(qu.size() > 1) {
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    } 
    cout << qu.front() << '\n';
}