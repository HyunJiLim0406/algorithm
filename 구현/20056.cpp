#include <iostream>
#include <vector>

using namespace std;

struct info {
    bool is_remain;
    int r, c, m, s, d;
};

int N;
vector<vector<vector<int>>> board;
vector<info> fire;
pair<int, int> dir[8] = {{-1, 0}, {-1, 1}, {0,  1}, {1,  1}, {1,  0}, {1,  -1}, {0,  -1}, {-1, -1}};

void moveFire(int idx) { //파이어볼 이동
    info cur = fire[idx];

    //한번에 이동
    int row = (cur.r + (cur.s * dir[cur.d].first)) % N;
    int col = (cur.c + (cur.s * dir[cur.d].second)) % N;

    //음수 처리
    if (row < 0)
        row += N;
    if (col < 0)
        col += N;

    board[row][col].push_back(idx); //board에 표시
    fire[idx].r = row;
    fire[idx].c = col;
}

void splitFire(int row, int col) { //파이어볼 분리
    vector<int> fires = board[row][col];
    int mass = 0, speed = 0, odd_cnt = 0, even_cnt = 0, size = fires.size();
    for (int i = 0; i < size; i++) {
        info &cur = fire[fires[i]];
        cur.is_remain = false; //기존 파이어볼 삭제
        mass += cur.m; //총 질량
        speed += cur.s; //총 속력
        (cur.d % 2 == 0) ? even_cnt++ : odd_cnt++; //방향 홀짝 체크
    }
    if (mass / 5 == 0) //질량이 0인지 확인
        return;
    int init = 1; //합쳐지는 파이어볼의 방향
    if (odd_cnt == 0 || even_cnt == 0) //전부 홀수 or 짝수라면 0부터 시작
        init = 0;
    for (int i = 0; i < 4; i++) { //새로운 파이어볼 추가
        fire.push_back({true, row, col, mass / 5, speed / size, init});
        init += 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fire.push_back({true, r - 1, c - 1, m, s, d});
    }

    while (K--) {
        board.assign(N, vector<vector<int>>(N, vector<int>(0))); //board 초기화
        for (int i = 0; i < fire.size(); i++) {
            if (fire[i].is_remain) //활성화된 파이어볼이라면 이동
                moveFire(i);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j].size() > 1) //파이어볼이 둘 이상 있다면
                    splitFire(i, j);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < fire.size(); i++) {
        if (fire[i].is_remain) //남아있는 파이어볼만 질량 계산
            result += fire[i].m;
    }
    cout << result;
}