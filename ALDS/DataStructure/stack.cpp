#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    s.push(3); s.push(7); s.push(1);

    cout << s.size() << " ";

    cout << s.top() << " ";
    s.pop();

    cout << s.top() << " ";
    s.pop();

    cout << s.top() << " ";
    
    s.push(5);

    cout << s.top() << " ";
    s.pop();


}