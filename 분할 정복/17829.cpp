#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix;

int divide(int row, int col, int n) {
    if (n == 1) //분할 종료
        return matrix[row][col];

    int size = n / 2;
    vector<int> arr;
    for (int i = 0; i < 2; i++) { //분할
        for (int j = 0; j < 2; j++)
            arr.push_back(divide(row + (i * size), col + (j * size), size));
    }
    sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
    return arr[1]; //두번째로 큰 수
}

int main() {
    int n;

    cin >> n;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << divide(0, 0, n);
}