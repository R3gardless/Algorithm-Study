// 백준 9012번 = 괄호

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N; // 표준 입력 사용하여 scanf 사용 X

    while(N--) {
        stack<char> s;
        string str;
        cin >> str;
        for(char c: str) {
            if(c == '(') s.push(c);
            else if(c == ')') { // c == ')'
                if(!s.empty() && s.top() == '(') s.pop();
                else s.push(c);
            }
        }
        if(!s.empty()) cout << "NO\n"; // 표준 출력 사용하여 printf 사용 X
        else cout << "YES\n"; // 표준 출력 사용하여 printf 사용 X
    }
    return 0;
}