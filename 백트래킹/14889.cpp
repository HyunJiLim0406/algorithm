#include <iostream>
#include <cmath>
using namespace std;

bool isTeam[20] = { 0, };
int pow_matrix[20][20];
int N, min_pow = 1000;

int cal_min() {
    int start_pow = 0, link_pow = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isTeam[i] && isTeam[j]) //체크 된거면 스타트팀
                start_pow += pow_matrix[i][j];
            if (!isTeam[i] && !isTeam[j]) //체크 안된건 링크팀
                link_pow += pow_matrix[i][j];
        }
    }
    return abs(start_pow - link_pow);
}

void split_team(int index, int player) {
    if (index == (N / 2)) { //절반 구하면 계산
        int result = cal_min();
        if (result < min_pow)
            min_pow = result;
        return; //이유도 모르게 계속 틀렸다고 해서 반례 다 돌려보고 했는데 걍 이거 리턴 안해서였음
    }
    for (int i = player + 1; i <= N; i++) { //조합이라고 생각하고 찾아야 중복 제거 가능
        if (!isTeam[i]) {
            isTeam[i] = true; //내려감
            split_team(index + 1, i);
            isTeam[i] = false; //올라감
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pow_matrix[i][j];
        }
    }
    split_team(0, 0);
    cout << min_pow;
}