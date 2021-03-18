#include <iostream>
#include <cmath> //sqrt 쓰면 실수 계산 오류 때문에 걍 다 제곱해버림

using namespace std;

int main() { //수학적 사고 요구
    int T;
    double x_1, x_2, y_1, y_2, r_1, r_2;

    cin >> T;
    for (int i = 0; i < T; i++) { //둘이 같은 좌표에 있을 때
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        double dist = pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2);
        double r_sub = pow(r_1 - r_2, 2);
        double r_add = pow(r_1 + r_2, 2);
        if (dist == 0) {
            if (r_1 == r_2)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        } else { //둘이 다른 좌표에 있을 때
            if (r_sub < dist && dist < r_add) //교점이 2개
                cout << 2 << endl;
            else if (r_add == dist || r_sub == dist) //외접, 내접
                cout << 1 << endl;
            else //만나지 않음
                cout << 0 << endl;
        }
    }
}