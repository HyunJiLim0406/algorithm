#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector<vector<pair<char, bool>>> board; //문자, 방문여부
int N, M;
bool isCycle;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> cur, pair<int, int> source) { //cur=이번에 탐색할 좌표, source=cur의 이전 좌표
    int row = cur.first;
    int col = cur.second;

    if (board[row][col].second) { //이미 방문했던 좌표면 사이클이 형성된 것
        isCycle = true;
        return;
    }
    board[row][col].second = true; //방문처리
    for (int i = 0; i < 4 && !isCycle; i++) { //상하좌우 확인
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && //범위 체크
            (board[row][col].first == board[nr][nc].first) && //같은 문자 확인
            ((nr != source.first) || (nc != source.second))) { //source 좌표가 아닌지 확인
            dfs(make_pair(nr, nc), cur);
        }
    }
}

int main() {
    string input;

    cin >> N >> M;
    board.assign(N, vector<pair<char, bool>>(M, make_pair(0, false)));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j].first = input[j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j].second) { //미방문 좌표
                dfs(make_pair(i, j), make_pair(-1, -1));
                if (isCycle) { //사이클 있음
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n"; //사이클 없음
}