#include <iostream>
#include <vector>

using namespace std;

string target;
vector<vector<char>> bridge;
vector<vector<vector<int>>> dp; //(i, j) 위치의 돌다리가 target[k]로 사용됨

int fillDp(int row, int col, int idx) {
    if (idx == target.size()) //다리를 다 건넘
        return 1;
    if (dp[row][col][idx] == -1) { //아직 확인하지 않은 상태
        dp[row][col][idx] = 0; //초기화
        int nr = (row + 1) % 2; //건너편 다리
        for (int i = col + 1; i < bridge[0].size(); i++) { //뛸 수 있는 돌다리 찾기
            if (bridge[nr][i] != target[idx])
                continue;
            dp[row][col][idx] += fillDp(nr, i, idx + 1); //갱신
        }
    }
    return dp[row][col][idx];
}

int main() {
    vector<string> input(2);

    cin >> target;
    for (int i = 0; i < 2; i++)
        cin >> input[i];
    bridge.assign(2, vector<char>(input[0].size() + 1));
    dp.assign(2, vector<vector<int>>(bridge[0].size(), vector<int>(target.size(), -1)));
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= input[i].size(); j++)
            bridge[i][j] = input[i][j - 1];
    }
    cout << fillDp(0, 0, 0) + fillDp(1, 0, 0); //천사부터 시작 + 악마부터 시작
}