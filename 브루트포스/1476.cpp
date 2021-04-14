#include <iostream>

using namespace std;

int main() {
    int E, S, M;

    cin >> E >> S >> M;
    E %= 15;
    S %= 28;
    M %= 19;

    int year = 1;
    while (true) { //그냥 무식하게 나눠보기
        if ((year % 15 == E) && (year % 28 == S) && (year % 19 == M)) {
            cout << year;
            break;
        }
        year++;
    }
}