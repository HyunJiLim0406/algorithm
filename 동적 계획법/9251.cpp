#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char source[1001], dest[1001];
int matrix[1001][1001];

/*원리 이해 못함
문자열 크기만큼 2차원 배열 만들고 만약 비교하는 두 문자가 같으면 (왼쪽 대각선 위 + 1)
다르면 왼쪽 or 위쪽에서 더 큰 애로 쓰면 되는데 왜 그런지는 이해하지 못했음.*/
int lcs() {
    int s_length = strlen(source);
    int d_length = strlen(dest);

    for (int i = 0; i < d_length; i++) {
        for (int j = 0; j < s_length; j++) {
            if (source[j] == dest[i])
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            else
                matrix[i + 1][j + 1] = max(matrix[i][j + 1], matrix[i + 1][j]);
        }
    }
    return matrix[d_length][s_length];
}

int main() {
    cin >> source >> dest;
    cout << lcs();
}