#include <iostream>
#include <map>
#include <string>

using namespace std;

const int DIVISOR = 1234567891;

int main() {
    map<char, int> m;
    char c = 'a';
    long long mul = 1, result = 0, L;
    string input;

    for (int i = 1; i <= 26; i++) {
        m[c] = i;
        c++;
    }
    cin >> L >> input;
    for (int i = 0; i < L; i++) {
        result += (m[input[i]] * mul);
        result %= DIVISOR;
        mul *= 31;
        mul %= DIVISOR;
    }
    cout << result;
}