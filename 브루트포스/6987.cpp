#include <iostream>
#include <vector>

using namespace std;

bool result;
vector<vector<int>> game_result, expectation;
vector<pair<int, int>> match;

void init() { //경기별 대결하게될 팀의 조합
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++)
            match.emplace_back(i, j);
    }
}

bool promising() { //실제 경기 결과와 예상한 것이 같은지 확인
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_result[i][j] != expectation[i][j])
                return false;
        }
    }
    return true;
}

void backtracking(int idx) {
    if (idx == 15) {
        if (result || !promising()) //이미 정답을 찾았거나 실제와 다름
            return;
        result = true;
        return;
    }
    int team1 = match[idx].first;
    int team2 = match[idx].second;

    //team1 = 승, team2 = 패
    expectation[team1][0]++;
    expectation[team2][2]++;
    backtracking(idx + 1);
    expectation[team1][0]--;
    expectation[team2][2]--;

    //team1 = 무, team2 = 무
    expectation[team1][1]++;
    expectation[team2][1]++;
    backtracking(idx + 1);
    expectation[team1][1]--;
    expectation[team2][1]--;

    //team1 = 패, team2 = 승
    expectation[team1][2]++;
    expectation[team2][0]++;
    backtracking(idx + 1);
    expectation[team1][2]--;
    expectation[team2][0]--;
}

int main() {
    int t = 4;

    init();
    while (t--) {
        result = false;
        game_result.assign(6, vector<int>(3));
        expectation.assign(6, vector<int>(3, 0));

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++)
                cin >> game_result[i][j];
        }
        backtracking(0);
        cout << result << ' ';
    }
}