// 백준 18258번 = 큐2

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, x;
string cmd;
queue<int> q;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    while(N--) {
        cin >> cmd;

        if(!cmd.compare("push")) {
            cin >> x;
            q.push(x);
        }
        
        else if(!cmd.compare("pop")) {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }

        else if(!cmd.compare("size")) {
            cout << q.size() << '\n';
        }

        else if(!cmd.compare("empty")) {
            cout << q.empty() << '\n';
        }

        else if(!cmd.compare("front")) {
            if(q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        
        else {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }
}