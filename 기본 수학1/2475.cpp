#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int result = 0, input;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        result += pow(input, 2);
    }
    cout << result % 10;
}