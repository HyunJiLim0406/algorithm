#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> op;
vector<vector<int>> dp_min, dp_max; //음수 * 음수 = 양수 최댓값 가능하므로 최솟값과 최댓값 저장

int calc(int num1, int num2, char op) { //단순 계산
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
}

int fillDp(int size) {
    vector<int> candi(4);
    for (int gap = 1; gap < size; gap++) {
        for (int start = 0; start < size - gap; start++) {
            int end = start + gap;
            dp_min[start][end] = INT32_MAX;
            dp_max[start][end] = INT32_MIN;
            for (int mid = start; mid < end; mid++) {
                candi[0] = calc(dp_min[start][mid], dp_min[mid + 1][end], op[mid]); //min op min
                candi[1] = calc(dp_min[start][mid], dp_max[mid + 1][end], op[mid]); //min op max
                candi[2] = calc(dp_max[start][mid], dp_min[mid + 1][end], op[mid]); //max op min
                candi[3] = calc(dp_max[start][mid], dp_max[mid + 1][end], op[mid]); //max op max
                sort(candi.begin(), candi.end()); //정렬

                dp_min[start][end] = min(dp_min[start][end], candi[0]); //최솟값 갱신
                dp_max[start][end] = max(dp_max[start][end], candi[3]); //최댓값 갱신
            }
        }
    }
    return dp_max[0][size - 1]; //결과
}

int main() {
    string expression;
    int N, idx = 0;

    cin >> N >> expression;
    op.assign(N / 2, '.');
    dp_min.assign(N / 2 + 1, vector<int>(N / 2 + 1, 0));
    dp_max.assign(N / 2 + 1, vector<int>(N / 2 + 1, 0));
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) { //dp 초기화
            dp_min[idx][idx] = expression[i] - '0';
            dp_max[idx][idx] = expression[i] - '0';
        } else
            op[idx++] = expression[i];
    }
    cout << fillDp(N / 2 + 1);
}