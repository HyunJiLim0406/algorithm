#include <iostream>
#include <vector>

using namespace std;
const int MAX = 5;

vector<int> cmd;
vector<vector<vector<int>>> dp;

int calcPower(int cur, int next) {
    if (cur == 0) //중앙에서 이동
        return 2;
    if (abs(cur - next) == 2) //반대편
        return 4;
    return 3; //인접
}

int fillDp(int idx, int left, int right) {
    if (idx == cmd.size()) //재귀 탈출
        return 0;
    if (dp[idx][left][right] == -1) { //아직 계산된 상태가 아니라면
        dp[idx][left][right] = 0; //초기화
        int next = cmd[idx];
        if (next == left || next == right) //같은 지점을 한 번 더 눌러야함
            dp[idx][left][right] = fillDp(idx + 1, left, right) + 1;
        else { //왼발 또는 오른발을 움직이는 방법 중에서 힘이 덜 드는 것
            int left_move = fillDp(idx + 1, next, right) + calcPower(left, next);
            int right_move = fillDp(idx + 1, left, next) + calcPower(right, next);
            dp[idx][left][right] = min(left_move, right_move);
        }
    }
    return dp[idx][left][right]; //리턴
}

int main() {
    int input;

    while (true) {
        cin >> input;
        if (!input)
            break;
        cmd.push_back(input);
    }
    dp.assign(cmd.size(), vector<vector<int>>(MAX, vector<int>(MAX, -1)));
    cout << fillDp(0, 0, 0);
}