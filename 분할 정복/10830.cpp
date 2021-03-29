#include <iostream>
#include <vector>

using namespace std;

const int DIVISOR = 1000;
vector<vector<int>> matrix;
vector<vector<int>> result;

vector<vector<int>> multiplyMatrix(int N, vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> res;
    vector<int> tmp;
    int input;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input = 0;
            for (int k = 0; k < N; k++) {
                input += (A[i][k] * B[k][j]);
            }
            input %= DIVISOR;
            tmp.push_back(input);
        }
        res.push_back(tmp);
        tmp.clear();
    }
    return res;
}

vector<vector<int>> divide(int N, long long B) {
    vector<vector<int>> tmp;

    if (B == 1) //더이상 나눌 수 없음
        return matrix;
    else {
        if (B % 2 == 0) { //짝수 거듭제곱일 때
            tmp = divide(N, B / 2);
            return multiplyMatrix(N, tmp, tmp);
        } else //홀수 거듭제곱일 때
            return multiplyMatrix(N, matrix, divide(N, B - 1));
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
        matrix.push_back(tmp);
        tmp.clear();
    }

    result = divide(N, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << result[i][j] % DIVISOR << ' '; //1000만 들어올 때
        cout << '\n';
    }
}