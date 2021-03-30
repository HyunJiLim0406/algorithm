#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long DIVISOR = 1000000007;
matrix init({
                    vector<long long>({1, 1}), //Fn-1, Fn
                    vector<long long>({1, 0})  //Fn, Fn-1
            });
matrix result;

matrix multiplyMatrix(int N, matrix A, matrix B) {
    matrix res(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++)
                res[i][j] += (A[i][k] * B[k][j]);
            res[i][j] %= DIVISOR;
        }
    }
    return res;
}

matrix divide(long long n) {
    matrix tmp;

    if (n == 1) //더이상 나눌 수 없음
        return init;
    else {
        if (n % 2 == 0) { //짝수 거듭제곱일 때
            tmp = divide(n / 2);
            return multiplyMatrix(2, tmp, tmp);
        } else //홀수 거듭제곱일 때
            return multiplyMatrix(2, init, divide(n - 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;

    cin >> n;

    result = divide(n);
    cout << result[0][1] % DIVISOR << '\n';
}