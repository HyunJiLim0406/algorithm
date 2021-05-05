#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> top_pos;

int cntDolls(vector<vector<int>> board, vector<int> moves) {
    int cnt = 0;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        if (top_pos[moves[i]] != board.size()) { //해당 열에 인형이 있다면
            int doll = board[top_pos[moves[i]]][moves[i] - 1]; //잡은 인형
            if ((!s.empty()) && (doll == s.top())) { //만약 연속해서 같은 인형이면
                cnt += 2;
                s.pop();
            } else //아니라면
                s.push(doll);
            top_pos[moves[i]]++; //해당 열 인형 하나 제거처리
        }
    }
    return cnt;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    top_pos.assign(board.size() + 1, board.size()); //각 열의 맨 위 인형의 위치 인덱스
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i] != 0) {
                top_pos[i + 1] = j;
                break;
            }
        }
    }
    int answer = cntDolls(board, moves);
    return answer;
}

int main() {
    cout << solution({{0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 3},
                      {0, 2, 5, 0, 1},
                      {4, 2, 4, 4, 2},
                      {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4});
}