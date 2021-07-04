#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player;
vector<int> entry = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //선수 순서
vector<vector<int>> board;

void running(int &run, int num) {
    run |= (1 << 0); //0번 플레이트에 선수 표시
    for (int i = (4 - num); i < 4; i++) {
        if (run & (1 << i)) { //홈에 도착하게 될 주자
            run &= ~(1 << i); //0으로 변경
            score++; //점수 증가
        }
    }
    run = run << num; //주자 이동
}

void playGame(int idx) {
    int out = 0, run = 0; //아웃카운트, 진루 상태
    while (out != 3) { //3아웃 미만일 동안
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) //아웃
            out++;
        else //존재하는 모든 주자 진루
            running(run, hit);
        player = (player + 1) % 9; //다음 선수
    }
}

int main() {
    int N, result = 0;

    cin >> N;
    board.assign(N, vector<int>(9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }
    do {
        swap(entry[0], entry[3]); //1번 선수 4번 타자 되도록
        score = player = 0; //초기화
        for (int i = 0; i < N; i++) //모든 이닝 플레이
            playGame(i);
        result = max(result, score); //최댓값 갱신
        swap(entry[3], entry[0]); //원래대로 복구
    } while (next_permutation(entry.begin() + 1, entry.end()));
    cout << result;
}