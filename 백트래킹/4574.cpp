#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

vector<vector<int>> board;
map<pp, bool> domino;
bool is_found;

void initDomino() { //사용 가능한 도미노 초기화
    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 9; j++) {
            domino[make_pair(i, j)] = true;
        }
    }
}

pp makePos(string pos) { //string 입력을 좌표로 변경
    int r = pos[0] - 'A';
    int c = (pos[1] - '0') - 1;
    return make_pair(r, c);
}

bool isPromise(pp pos, int num) { //해당 위치에 숫자 입력 가능한지 확인
    int row = pos.first;
    int col = pos.second;
    int r_sector = row / 3;
    int c_sector = col / 3;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i == row) && (j == col))
                continue;
            if (((i == row) || (j == col)) && (board[i][j] == num)) //같은 행 또는 열에 이미 숫자가 있음
                return false;
            else if (((i / 3) == r_sector) && ((j / 3) == c_sector) && (board[i][j] == num)) //같은 구역에 이미 숫자가 있음
                return false;
        }
    }
    return true;
}

void inputDomino(pp domino_pos, pp board_input, pp pos1, pp pos2){ //도미노 넣기
    domino[domino_pos] = false;
    board[pos1.first][pos1.second] = board_input.first;
    board[pos2.first][pos2.second] = board_input.second;
}

void retrieveDomino(pp domino_pos, pp pos1, pp pos2){ //도미노 뺴기
    domino[domino_pos] = true;
    board[pos1.first][pos1.second] = 0;
    board[pos2.first][pos2.second] = 0;
}

void backtracking(int cnt) {
    if (cnt == 81) { //결과 찾음
        is_found = true;
        return;
    }
    int r = cnt / 9; //행
    int c = cnt % 9; //열
    if (board[r][c] == 0) { //빈공간이라면
        vector<pp> tmp;
        if ((r + 1 < 9) && (board[r + 1][c] == 0)) //세로 배치
            tmp.push_back(make_pair(r + 1, c));
        if ((c + 1 < 9) && (board[r][c + 1] == 0)) //가로 배치
            tmp.push_back(make_pair(r, c + 1));
        if (tmp.size() == 0) //도미노 배치할 수 없음
            return;
        for (auto iter = domino.begin(); iter != domino.end(); iter++) { //남아있는 도미노 넣어보기
            if (!iter->second) //이미 배치한 도미노
                continue;
            if (isPromise(make_pair(r, c), iter->first.first)) { //똑바로 넣어보기
                for (int i = 0; i < tmp.size(); i++) {
                    if (isPromise(tmp[i], iter->first.second)) {
                        inputDomino(iter->first, iter->first, make_pair(r, c), tmp[i]); //visited 처리
                        backtracking(cnt + 1); //백트래킹 호출
                        if (is_found) //이미 답을 찾았다면 리턴
                            return;
                        retrieveDomino(iter->first, make_pair(r, c), tmp[i]); //unvisited 처리
                    }
                }
            }
            if (isPromise(make_pair(r, c), iter->first.second)) { //반대로 넣어보기
                for (int i = 0; i < tmp.size(); i++) {
                    if (isPromise(tmp[i], iter->first.first)) {
                        inputDomino(iter->first, make_pair(iter->first.second, iter->first.first), make_pair(r, c), tmp[i]); //visited 처리
                        backtracking(cnt + 1); //백트래킹 호출
                        if (is_found) //이미 답을 찾았다면 리턴
                            return;
                        retrieveDomino(iter->first, make_pair(r, c), tmp[i]); //unvisited 처리
                    }
                }
            }
        }
    } else //이미 채워져있으면 백트래킹 호출
        backtracking(cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int input, puzzle_cnt = 1;
    string single_input;
    pair<int, string> input_info[2];
    pp pos;

    while (true) {
        cin >> input;
        if (input == 0) //입력 종료
            break;

        is_found = false;
        initDomino();
        board.assign(9, vector<int>(9, 0));
        for (int i = 0; i < input; i++) {
            for (int j = 0; j < 2; j++) { //좌표 받아서 board에 입력
                cin >> input_info[j].first >> input_info[j].second;
                pos = makePos(input_info[j].second);
                board[pos.first][pos.second] = input_info[j].first;
            }
            if (input_info[0].first > input_info[1].first) //오름차순 정렬
                swap(input_info[0], input_info[1]);
            domino[make_pair(input_info[0].first, input_info[1].first)] = false; //도미노 사용 처리
        }
        for (int i = 1; i <= 9; i++) { //좌표 받아서 board에 입력
            cin >> single_input;
            pos = makePos(single_input);
            board[pos.first][pos.second] = i;
        }
        cout << "Puzzle " << puzzle_cnt << '\n'; //출력
        backtracking(0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j];
            cout << '\n';
        }
        puzzle_cnt++;
    }
}