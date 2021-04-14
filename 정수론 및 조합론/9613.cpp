#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int gcd(int a, int b) { //유클리드 호제법으로 구한 최대 공약수
    int tmp;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll sumGcd(vector<int> arr) { //모든 최대 공약수의 합이 int 범위를 넘을 수도 있음
    ll sum = 0;

    if (arr.size() == 1) //숫자가 하나만 들어올 수도 있음
        return 0;
    for (int i = 0; i < arr.size() - 1; i++) { //가능한 모든 쌍에 대해
        for (int j = i + 1; j < arr.size(); j++)
            sum += gcd(arr[i], arr[j]);
    }
    return sum;
}

int main() {
    int t, n, input;
    vector<int> arr;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> input;
            arr.push_back(input);
        }
        cout << sumGcd(arr) << '\n';
        arr.clear();
    }
}