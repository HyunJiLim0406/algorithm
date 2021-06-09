#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

vector<vector<bool>> board(101, vector<bool>(101, false));
vector<int> dir_list; //각 커브의 방향 정보
pp dir[4] = {{0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0}}; //하

pp makeCurve(pp start) {
    int r = start.first; //시작점의 행
    int c = start.second; //시작점의 열
    int size = dir_list.size(); //방향 정보 저장 리스트의 크기
    for (int i = size - 1; i >= 0; i--) { //뒤에서부터(스택)
        int nd = (dir_list[i] + 1) % 4; //새로운 방향
        r += dir[nd].first;
        c += dir[nd].second;
        board[r][c] = true; //드래곤 커브 표시
        dir_list.push_back(nd); //새로운 방향 입력
    }
    return make_pair(r, c); //이번 세대의 끝 점
}

int cntSquare() { //사각형의 개수 세기
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int N, x, y, d, g;

    cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        pp end_point = make_pair(y + dir[d].first, x + dir[d].second); //0세대의 끝점
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 표시
        dir_list.push_back(d); //0세대 방향 입력
        for (int i = 0; i < g; i++) //끝점 갱신하며 각 세대의 커브 만들기
            end_point = makeCurve(end_point);
        dir_list.clear(); //새로운 커브 만들기 전 초기화
    }
    cout << cntSquare(); //사각형의 수
}