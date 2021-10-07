#include <iostream>
#include <vector>

using namespace std;

int ans = 3001;
vector<vector<int>> cost;
vector<vector<bool>> check;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

bool promising(int row, int col) {
    if (check[row][col])
        return false;
    for (int i = 0; i < 4; i++) {
        if (check[row + dir[i].first][col + dir[i].second])
            return false;
    }
    return true;
}

int reverse(int row, int col) {
    int sum = cost[row][col]; //심는 가격
    check[row][col] = !check[row][col];
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        sum += cost[nr][nc];
        check[nr][nc] = !check[nr][nc];
    }
    return sum;
}

void backtracking(int n, int cnt, int cur_cost) {
    if (cnt == 3) { //기저조건
        ans = min(ans, cur_cost);
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (promising(i, j)) { //심을 수 있으면
                int sum = reverse(i, j); //심기
                backtracking(n, cnt + 1, cur_cost + sum);
                reverse(i, j); //심기 취소
            }
        }
    }
}

int main() {
    int n;

    cin >> n;
    cost.assign(n, vector<int>(n, 0));
    check.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }
    backtracking(n, 0, 0);
    cout << ans;
}