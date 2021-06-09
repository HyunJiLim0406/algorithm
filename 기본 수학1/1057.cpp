#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a, b;

    cin >> N >> a >> b;
    if (a > b)
        swap(a, b);
    int result = 1;
    while (b - a != 1 || a % 2 == 0) {
        a = (a % 2 == 1) ? ((a + 1) / 2) : a / 2;
        b = (b % 2 == 1) ? ((b + 1) / 2) : b / 2;
        result++;
    }
    cout << result;
}