#include <iostream>
#include <vector>

using namespace std;

int calcGCD(int a, int b) { //유클리드 호제법
    if (a < b)
        swap(a, b);
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int N, sum = 0;

    cin >> N;
    vector<int> input(N, 0), arr(N - 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        if (i > 0) { //두 가로수의 차를 구하고, 누적합 계산해두기
            arr[i - 1] = (input[i] - input[i - 1]);
            sum += arr[i - 1];
        }
    }
    int gcd = calcGCD(arr[0], arr[1]); //연쇄적으로 gcd 계산해서 최종 gcd 구하기
    for (int i = 2; i < N - 1; i++)
        gcd = calcGCD(gcd, arr[i]);
    cout << sum / gcd - (N - 1);
}