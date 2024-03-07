// 백준 2257번 = 화학식량

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

stack<int> st;

int tmp, m, res;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;

    for(char c: str) {
        if(c >= '1' && c <= '9') {
            tmp = st.top(); st.pop();
            m = tmp * (c - '0');
            st.push(m);    
        }
        else if(c >= 'A' && c <= 'Z') {
            if(c == 'H') st.push(1);
            else if(c == 'C') st.push(12);
            else st.push(16);
        }
        else if(c == '(') st.push(0);
        else {
            m = 0;
            while(true) {
                tmp = st.top(); st.pop();
                if(!tmp) {
                    st.push(m);
                    break;
                }
                m += tmp;
            }
        }
    }
    
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    
    cout << res << '\n';

    return 0;
}
