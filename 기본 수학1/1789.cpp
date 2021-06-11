#include <iostream>
#include <cmath>

using namespace std;

int main() { //수학적으로 접근
    long long S;

    cin >> S;
    long long num = sqrt(S * 2);
    if (num * (num + 1) <= (S * 2))
        cout << num;
    else
        cout << num - 1;
}