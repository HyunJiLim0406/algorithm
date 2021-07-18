#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, pair<int, int>> dir;

pair<int, int> move(string cmd, pair<int, int> pos) { //이동
    int r = pos.first, c = pos.second;
    for (int i = 0; i < cmd.size(); i++) {
        r += dir[cmd[i]].first;
        c += dir[cmd[i]].second;
    }
    return make_pair(r, c);
}

bool isOut(pair<int, int> pos) { //범위 확인
    return pos.first < 0 || pos.first >= 8 || pos.second < 0 || pos.second >= 8;
}

string makePos(pair<int, int> pos) {
    string result;
    result += pos.second + 'A'; //열
    result += (pos.first + 1) + '0'; //행
    return result;
}

int main() {
    dir['R'] = make_pair(0, 1);
    dir['L'] = make_pair(0, -1);
    dir['B'] = make_pair(-1, 0);
    dir['T'] = make_pair(1, 0);
    vector<pair<int, int>> piece(2);
    string input;
    int N;

    for (int i = 0; i < 2; i++) {
        cin >> input;
        piece[i] = make_pair((input[1] - '0') - 1, input[0] - 'A'); //행, 열
    }
    cin >> N;
    while (N--) {
        cin >> input;
        pair<int, int> king_pos = move(input, piece[0]); //킹 이동
        if (isOut(king_pos)) //범위 벗어남
            continue;
        if (king_pos == piece[1]) { //킹이 갈 곳에 말이 있음
            pair<int, int> p_pos = move(input, piece[1]); //말 이동
            if (isOut(p_pos)) //범위 벗어남
                continue;
            piece[1] = p_pos; //위치 갱신
        }
        piece[0] = king_pos; //위치 갱신
    }
    for (int i = 0; i < 2; i++)
        cout << makePos(piece[i]) << '\n';
}