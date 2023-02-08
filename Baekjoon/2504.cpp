// 백준 2504번 = 괄호의 값

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<int> st;
stack<char> st2;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int sum = 0, tmp;
 
    cin >> str;

    for(char ch: str) {
        if(ch == '(' || ch == '[') {
            st.push(0); st2.push(ch);
        }
        else if(ch == ')') {
            if(!st2.empty() && st2.top() == '(') st2.pop();
            else st2.push(ch);

            if(!st.empty() && st.top() == 0) {
                st.pop(); st.push(2); 
            }
            else {
                int sum = 0;
                while(!st.empty()) {
                    tmp = st.top();
                    if(tmp == 0) {
                        st.pop(); st.push(sum * 2);
                        break;
                    }
                    sum += tmp; st.pop();
                }
            }
        }
        else {
            if(!st2.empty() && st2.top() == '[') st2.pop();
            else st2.push(ch);

            if(!st.empty() && st.top() == 0) {
                st.pop(); st.push(3); 
            }
            else {
                int sum = 0;
                while(!st.empty()) {
                    tmp = st.top();
                    if(tmp == 0) {
                        st.pop(); st.push(sum * 3);
                        break;
                    }
                    sum += tmp; st.pop();
                }
            }
        }
    }
    if(!st2.empty()) cout << "0\n";
    else {
        sum = 0;
        while(!st.empty()) {
            sum += st.top(); st.pop();
        }
        cout << sum << '\n';
    }
    return 0;
}