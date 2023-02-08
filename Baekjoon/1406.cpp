// 백준 1406번 = 에디터

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
char cmd, c, tmp;
string str, answer;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<char> st1, st2;

    cin >> str >> N;

    for(char c: str) st1.push(c);

    while(N--) {
        cin >> cmd;
        if(cmd == 'P') {
            cin >> c;
            st1.push(c);
        }
        else if(cmd == 'L') {
            if(!st1.empty()) {
                tmp = st1.top();
                st1.pop(); st2.push(tmp); 
            }
        }
        else if(cmd == 'D') {
            if(!st2.empty()) {
                tmp = st2.top();
                st2.pop(); st1.push(tmp);
            }
        }
        else { // B
            if(!st1.empty()) st1.pop();
        }

    }

    while(!st1.empty()) { // string concat 시도할 경우 틀림
        tmp = st1.top();
        st1.pop(); st2.push(tmp);
    }
    while(!st2.empty()) {
        answer += st2.top(); st2.pop();
        // cout << st2.top(); st2.pop();
    }
    
    cout << answer;
    return 0;
}