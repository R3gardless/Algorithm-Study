// 백준 1935번 = 후위표기식2

#include <iostream>
#include <stack>

using namespace std;

stack<double> s;

double a, b;
int N, num_char[26];
string str;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> str;

    for(int i = 0; i < N; ++i) {
        cin >> num_char[i];
    }

    for(char c: str) {
        if(c == '*') {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(a * b);
        }
        else if(c == '/') {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(b / a);
        }
        else if(c == '+') {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(a + b);
        }
        else if(c == '-') {
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(b - a);
        }
        else {
            s.push(num_char[c-'A']);
        }
    }
    printf("%.2f", s.top());
    
    return 0;
}