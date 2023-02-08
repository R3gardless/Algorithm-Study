#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int N;
vector<int> v, g;


void shell_insertionSort(int g) {
    int i, j, temp;
    for(i = g; i < N; ++i) {
        temp = v[i];
        j = i - g;
        while(j >= 0  && v[j] > temp) {
             v[j + g] = v[j];
             j -= g;
        }
        v[j + g] = temp;
    }

}

void shellSort() {
    for(int h = 1;;) {
        if(h > N) break;
        g.push_back(h);
        h = 3 * h + 1;
    }    
    for(int i = g.size() - 1; i >= 0; --i) {
        shell_insertionSort(g[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d", &N);

    v.assign(N, 0);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    shellSort();

    for(auto i: v) cout << i << ' ';
    
    return 0;
}