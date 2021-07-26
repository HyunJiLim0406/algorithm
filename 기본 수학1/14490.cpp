#include <iostream>
#include <string>

using namespace std;

int gcd(int n, int m) { //최대공약수
    int tmp;
    if (n < m)
        swap(n, m);
    while (m) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}

int main() {
    string str;

    cin >> str;
    int idx = str.find(':');
    int n = stoi(str.substr(0, idx)); //앞부분 자르기
    int m = stoi(str.substr(idx + 1)); //뒷부분 자르기
    int div = gcd(n, m);
    cout << n / div << ':' << m / div;
}