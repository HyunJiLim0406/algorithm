#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int matrix[4][4], N, M;

int calc(int num) {
    int result = 0;
    bool checked[16] = {0};
    for (int i = 0; i < N * M; i++) {
        if (!checked[i]) { //방문 여부 확인
            if (((1 << i) & num) == 0) { //0이면 가로 블럭
                checked[i] = true;
                string horizontal = to_string(matrix[i / M][i % M]);
                for (int j = i + 1; j % M != 0; j++) { //가로 탐색
                    if (((1 << j) & num) != 0) //세로 블럭이면 break
                        break;
                    checked[j] = true;
                    horizontal += to_string(matrix[j / M][j % M]);
                }
                result += stoi(horizontal); //결과에 더함
            } else if (((1 << i) & num) != 0) { //1이면 세로 블럭
                checked[i] = true;
                string vertical = to_string(matrix[i / M][i % M]);
                for (int j = i + M; j / M < N; j += M) { //세로 탐색
                    if (((1 << j) & num) == 0) //가로 블럭이면 break
                        break;
                    checked[j] = true;
                    vertical += to_string(matrix[j / M][j % M]);
                }
                result += stoi(vertical); //결과에 더함
            }
        }
    }
    return result;
}

int main() {
    string tmp;
    int max_sum = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++)
            matrix[i][j] = tmp[j] - '0';
    }
    for (int i = 0; i < (1 << (N * M)); i++) //N=2, M=2일 때 0000부터 1111까지
        max_sum = max(max_sum, calc(i));
    cout << max_sum;
}