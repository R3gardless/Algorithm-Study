// 11279번 = 최대 힙

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator() (const int & a,const int & b) {
        return a < b;
    }
};

priority_queue<int, vector<int>, compare> pq;
int N, n;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    while(N--) {
        cin >> n;

        if(n != 0) pq.push(n);
        else {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;

}