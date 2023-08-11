// 1202번 = 보석 도둑

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Gem {
    int m;
    int v;
    Gem(int m1, int v1) : m(m1), v(v1) {};
};

struct compare_mass {
    bool operator() (const Gem & gem1, const Gem & gem2) {
        return gem1.m > gem2.m;
    }
};

struct compare_value {
    bool operator() (const Gem & gem1, const Gem & gem2) {
        return gem1.v < gem2.v;
    }
};

priority_queue<Gem, vector<Gem>, compare_mass> pqMass;
priority_queue<Gem, vector<Gem>, compare_value> pqValue;
vector<int> pqBag;
int N, K, C;
int m, v, c, bag;
ll cost;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    pqBag.resize(K);

    for(int i = 0; i < N; ++i) {
        cin >> m >> v;
        pqMass.push(Gem(m,v));
    }

    for(int i = 0; i < K; ++i) {
        cin >> pqBag[i];
    }

    sort(pqBag.begin(), pqBag.end());

    for(int i = 0; i < K; ++i) {
        bag = pqBag[i];

        while(bag >= pqMass.top().m && !pqMass.empty()) {
            pqValue.push(pqMass.top());
            pqMass.pop();
        }

        if(!pqValue.empty()) {
            cost += pqValue.top().v;
            pqValue.pop();
        }
    }
    cout << cost << '\n';

    return 0;
}