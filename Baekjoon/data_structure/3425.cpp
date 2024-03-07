// 3425번 = 고스택

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#define MAX 1000000000
using namespace std;
typedef long long ll;

vector<pair<string, ll> > cmdVec;
stack<ll> s;
string cmd;
ll N, V, n, a, b;

bool init() {
    cin >> cmd;
    while(true) {
        if(!cmd.compare("QUIT")) {
            return false;
        }
        else {
            if(!cmd.compare("NUM")) {
                cin >> n;
                cmdVec.push_back(make_pair(cmd, n));
            } else {
                if(!cmd.compare("END")) return true;
                cmdVec.push_back(make_pair(cmd, 0));
            }
        }
        cin >> cmd;
    }
}

bool goStack() {
    for(auto cmd : cmdVec) {
        if(!cmd.first.compare("NUM")) {
            s.push(cmd.second);
        } else if(!cmd.first.compare("POP")) {
            if(s.empty()) return false;
            s.pop();
        } else if(!cmd.first.compare("INV")) {
            if(s.empty()) return false;
            a = s.top(); s.pop();
            s.push(-a);
        } else if(!cmd.first.compare("DUP")) {
            if(s.empty()) return false;
            a = s.top();
            s.push(a);
        } else if(!cmd.first.compare("SWP")) {
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            s.push(a); s.push(b);
        } else if(!cmd.first.compare("ADD")) {
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(abs(a + b) > MAX) return false;
            s.push(a + b);
        } else if(!cmd.first.compare("SUB")) {
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(abs(b - a) > MAX) return false;
            s.push(b - a);
        } else if(!cmd.first.compare("MUL")) {
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(abs(a * b) > MAX) return false;
            s.push(a * b);
        } else if(!cmd.first.compare("DIV")) {
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(a == 0) return false;
            s.push(b / a);
        } else if(!cmd.first.compare("MOD")){
            if(s.size() < 2) return false;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            if(a == 0) return false;
            s.push(b % a);
        }
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cmdVec.clear();
        if(!init()) break;
        else { 
            cin >> N;
            while(N--) {
                while(!s.empty()) s.pop();
                cin >> V;
                s.push(V);
                if(!goStack() || s.size() != 1) {
                    cout << "ERROR\n";
                }
                else cout << s.top() << '\n';
            }
            cout << '\n';
        }
    }
    return 0;
}