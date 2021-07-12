#include <iostream>
#include <vector>

using namespace std;

void calcRemain(int num, int mul, vector<int> &arr) {
    while (num) { //자릿수 하나하나 확인
        arr[num % 10] += mul;
        num /= 10;
    }
}

int main() {
    int N;

    cin >> N;
    vector<int> arr(10, 0);
    int S = 1, mul = 1;
    while (S <= N) {
        while (N % 10 != 9 && S <= N) { //N의 끝자리를 9로
            calcRemain(N, mul, arr);
            N--;
        }
        if (S > N) //대소 관계 역전
            break;
        while (S % 10 != 0 && S <= N) { //S의 끝자리를 0으로
            calcRemain(S, mul, arr);
            S++;
        }
        S /= 10;
        N /= 10;
        for (int i = 0; i < 10; i++) //등장 횟수
            arr[i] += (N - S + 1) * mul;
        mul *= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
}