#include <iostream>

using namespace std;

int main() {
    int N, M, K, cnt = 0, team_cnt;

    cin >> N >> M >> K;
    while (N < (M * 2)) { //N, M명의 학생으로 만들 수 있는 최대 팀 수
        M--;
        cnt++; //잉여 자원(남학생)
    }
    team_cnt = M; //최대 팀 수
    cnt += (N - (M * 2)); //잉여 자원(여학생)
    while (cnt < K) { //K명 충족하지 못했으면 1팀씩 해체
        cnt += 3;
        team_cnt--;
    }
    cout << team_cnt;
}