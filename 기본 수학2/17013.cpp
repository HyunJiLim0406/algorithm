#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 1000001;

bool isPrime[MAX];

void eratos() { //에라토스테네스의 체
    fill(isPrime + 2, isPrime + MAX, 1); //0과 1은 소수가 아님

    int line = sqrt(MAX) + 1; //제곱근까지만 계산
    for (int i = 2; i <= line; i++) {
        if (isPrime[i]) { //소수의 배수들을 모두 false 처리
            for (int j = i * 2; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int input, T;

    eratos(); //미리 소수 전부 찾아 놓음
    cin >> T;
    for (int i = 0; i < T; i++) {
        int cnt = 0;

        cin >> input;
        for (int j = 2; j <= (input / 2); j++) { //중복 피하려 절반 까지만
            if (isPrime[j] && isPrime[input - j])
                cnt++;
        }
        cout << cnt << '\n';
    }
}