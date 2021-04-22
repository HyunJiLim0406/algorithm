#include <iostream>
#include <string>

using namespace std;

int main() {
    string N;
    int B, num, result = 0;

    cin >> N >> B;
    int mul = 1;
    for (int i = N.size() - 1; i >= 0; i--) {
        if ((N[i] >= 'A') && (N[i] <= 'Z')) //아스키 코드
            num = (N[i] - '0') - 7;
        else
            num = N[i] - '0';
        result += (num * mul);
        mul *= B;
    }
    cout << result;
}