#include <iostream>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

bool cmp(const point& p1, const point& p2) { //p1이 p2보다 앞에 있어야하는 조건
    if (p1.x < p2.x)
        return true;
    else if (p1.x == p2.x)
        return p1.y < p2.y;
    else
        return false;
}

int main() {
    int N, i;

    cin >> N;
    point* arr = new point[N];
    for (i = 0; i < N; i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + N, cmp); //구조체처럼 복잡한 비교는 세번째 인자를 건네줘서 할 수 있음
    for (i = 0; i < N; i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';
}