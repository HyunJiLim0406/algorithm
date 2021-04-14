#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 1000000;

bool isPrime[MAX];

void eratos() { //에라토스테네스의 체
    fill(isPrime+2, isPrime+MAX, 1); //0과 1은 소수가 아님

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

    int input;

    eratos(); //미리 소수 전부 찾아 놓음
    while (true) {
        bool isGoldbach = false;

        cin >> input;
        if (input == 0) //종료조건
            break;
        for (int i = 3; i <= (input / 2); i++) { //3부터 input의 절반까지 소수 탐색
            if (isPrime[i] && isPrime[input - i]) {
                isGoldbach = true;
                cout << input << " = " << i << " + " << input - i << '\n';
                break;
            }
        }
        if (!isGoldbach) //소수의 합으로 나타낼 수 없음
            cout << "Goldbach's conjecture is wrong.\n";
    }
}