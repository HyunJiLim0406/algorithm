#include <iostream>
#include <vector>

using namespace std;
const int FIN = 32;

struct pos {
    bool is_piece;
    int score;
    int next_idx[5];
};

pos map[33] = {{false, 0,  {1,   2,   3,   4,   5}},
               {false, 2,  {2,   3,   4,   5,   10}},
               {false, 4,  {3,   4,   5,   10,  11}},
               {false, 6,  {4,   5,   10,  11,  12}},
               {false, 8,  {5,   10,  11,  12,  13}},
               {false, 10, {6,   7,   8,   9,   25}},
               {false, 13, {7,   8,   9,   25,  26}},
               {false, 16, {8,   9,   25,  26,  27}},
               {false, 19, {9,   25,  26,  27,  FIN}},
               {false, 25, {25,  26,  27,  FIN, FIN}},
               {false, 12, {11,  12,  13,  14,  17}},
               {false, 14, {12,  13,  14,  17,  18}},
               {false, 16, {13,  14,  17,  18,  19}},
               {false, 18, {14,  17,  18,  19,  20}},
               {false, 20, {15,  16,  9,   25,  26}},
               {false, 22, {16,  9,   25,  26,  27}},
               {false, 24, {9,   25,  26,  27,  FIN}},
               {false, 22, {18,  19,  20,  21,  28}},
               {false, 24, {19,  20,  21,  28,  29}},
               {false, 26, {20,  21,  28,  29,  30}},
               {false, 28, {21,  28,  29,  30,  31}},
               {false, 30, {22,  23,  24,  9,   25}},
               {false, 28, {23,  24,  9,   25,  26}},
               {false, 27, {24,  9,   25,  26,  27}},
               {false, 26, {9,   25,  26,  27,  FIN}},
               {false, 30, {26,  27,  FIN, FIN, FIN}},
               {false, 35, {27,  FIN, FIN, FIN, FIN}},
               {false, 40, {FIN, FIN, FIN, FIN, FIN}},
               {false, 32, {29,  30,  31,  27,  FIN}},
               {false, 34, {30,  31,  27,  FIN, FIN}},
               {false, 36, {31,  27,  FIN, FIN, FIN}},
               {false, 38, {27,  FIN, FIN, FIN, FIN}},
               {false, 0,  {FIN, FIN, FIN, FIN, FIN}}};

int max_score = 0;
vector<int> dice(10), piece(4);

void backtracking(int idx, int tmp) {
    if (idx == 10) { //탐색 종료
        max_score = max(max_score, tmp);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (piece[i] == FIN) //이미 도착지점에 있는 말
            continue;
        int next_pos = map[piece[i]].next_idx[dice[idx] - 1], saved = piece[i]; //다음 위치와 원래 위치
        if (!map[next_pos].is_piece || next_pos == FIN) { //다음 위치가 도착점이거나 말이 없는 곳일 때
            map[saved].is_piece = false;
            map[next_pos].is_piece = true;
            piece[i] = next_pos;
            backtracking(idx + 1, tmp + map[next_pos].score);
            map[saved].is_piece = true;
            map[next_pos].is_piece = false;
            piece[i] = saved;
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    backtracking(0, 0);
    cout << max_score;
}