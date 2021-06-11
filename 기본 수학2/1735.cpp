#include <iostream>

using namespace std;

int gcd(int x, int y) { //최대공배수
    int tmp;
    if (y > x) //대소관계
        swap(x, y);
    while (y != 0) { //유클리드 호제법
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

int main() {
    int a1, b1, a2, b2;

    cin >> a1 >> b1 >> a2 >> b2;
    int plus_b = b1 * b2 / gcd(b1, b2); //공통 분모
    int plus_a = a1 * (plus_b / b1) + a2 * (plus_b / b2); //분자
    int div = gcd(plus_b, plus_a); //더하고 나서 나눠지는지 확인
    cout << plus_a / div << ' ' << plus_b / div;
}