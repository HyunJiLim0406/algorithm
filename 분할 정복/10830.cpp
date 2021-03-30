#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
const int DIVISOR = 1000;
matrix inputA;
matrix result;

matrix multiplyMatrix(int N, matrix A, matrix B) {
    matrix res(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++)
                res[i][j] += (A[i][k] * B[k][j]);
            res[i][j] %= DIVISOR;
        }
    }
    return res;
}

matrix divide(int N, long long B) {
    matrix tmp;

    if (B == 1) //더이상 나눌 수 없음
        return inputA;
    else {
        if (B % 2 == 0) { //짝수 거듭제곱일 때
            tmp = divide(N, B / 2);
            return multiplyMatrix(N, tmp, tmp);
        } else //홀수 거듭제곱일 때
            return multiplyMatrix(N, inputA, divide(N, B - 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, input;
    long long B;
    vector<int> tmp;

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            tmp.push_back(input);
        }
        inputA.push_back(tmp);
        tmp.clear();
    }

    result = divide(N, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << result[i][j] % DIVISOR << ' '; //1000만 들어올 때
        cout << '\n';
    }
}