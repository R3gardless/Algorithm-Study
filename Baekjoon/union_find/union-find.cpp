#include <iostream>

using namespace std;

const int MAX = 100;

int p[MAX];

int find(int n) {
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[b] = a;
}