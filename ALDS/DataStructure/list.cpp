#include <iostream>
#include <list>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    list<char> L;

    L.push_front('b'); // [b]
    L.push_back('c'); // [bc]
    L.push_front('a'); // [abc]

    cout << L.front(); // a
    cout << L.back(); // c

    L.pop_front(); // [bc]
    L.push_back('d'); // [bcd]

    cout << L.front(); // b
    cout << L.back() << "\n"; // d

    return 0;
}