#include <iostream>
#include <cmath>

using namespace std;

struct Point { double x, y; };

int n;

void koch(int n, Point a, Point b) {
    if(n == 0) return;

    Point s, t, u;

    double th = M_PI * 60.0 / 180.0; // degree to radian, M_PI = 3.141592...

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x; // 점 u = 점 t를 점 s 기반으로 반시계 방향으로 60도 회전
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y; // 점 u = 점 t를 점 s 기반으로 반시계 방향으로 60도 회전
    
    koch(n-1, a, s);
    cout << s.x << ' ' << s.y << '\n';
    koch(n-1, s, u);
    cout << u.x << ' ' <<  u.y << '\n';
    koch(n-1, u, t);
    cout << t.x << ' ' <<  t.y << '\n';
    koch(n-1, t, b);

}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    Point start, end;

    cout.precision(10);

    start.x = 0; start.y = 0;
    end.x = 100; end.y = 0;

    cout << start.x << ' ' << start.y << '\n';
    koch(n, start, end);
    cout << end.x << ' ' << end.y << '\n';
    
    return 0;
}
