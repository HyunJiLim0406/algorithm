#include <iostream>
using namespace std;

int main() { //최소공배수 * 최대공배수 = A * B
    int A, B;
    int gcf, lcm;

    cin >> A >> B;
    if (A > B) { //작은게 앞으로 오도록
        int temp = A;
        A = B;
        B = temp;
    }
    for (int i = A; i >= 1; i--) {
        if (A % i == 0 && B % i == 0) {
            gcf = i;
            lcm = A * B / gcf;
            break;
        }
    }
    cout << gcf << '\n' << lcm;
}