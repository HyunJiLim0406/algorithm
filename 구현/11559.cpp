#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef pair<int, int> pp;

vector<vector<char>> board;
vector<vector<int>> visited;
pp dir[4] = {{-1, 0},
             {1,  0},
             {0,  -1},
             {0,  1}};

int dfs(int r, int c, int mark) {
    int cnt = 1;
    visited[r][c] = mark; //방문 표시
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr < 0) || (nr >= 12) || (nc < 0) || (nc >= 6)) //범위 확인
            continue;
        if (board[nr][nc] == board[r][c] && !visited[nr][nc]) //같은 색이며 방문한 적 없는 뿌요
            cnt += dfs(nr, nc, mark);
    }
    return cnt;
}

set<int> findBomb() {
    set<int> result;
    visited.assign(12, vector<int>(6, 0));
    int mark = 1; //인덱스
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (board[i][j] != '.' && !visited[i][j]) { //미방문 뿌요
                int num = dfs(i, j, mark); //dfs하며 인덱스 표시
                if (num >= 4) //해당 인덱스의 뿌요가 4개 이상이라면 터질 것
                    result.insert(mark);
                mark++;
            }
        }
    }
    return result;
}

void changeBoard(set<int> bomb) {
    queue<char> q;
    vector<vector<char>> tmp(12, vector<char>(6, '.')); //'.'으로 채운 임시 판
    for (int i = 0; i < 6; i++) {
        for (int j = 11; j >= 0; j--) {
            if (bomb.find(visited[j][i]) == bomb.end()) //한 열에 대해 터질 뿌요가 아니라면 큐에 삽입
                q.push(board[j][i]);
        }
        int pos = 11;
        while(!q.empty()){ //뿌요 입력
            tmp[pos--][i] = q.front();
            q.pop();
        }
    }
    board = tmp; //board 갱신
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    board.assign(12, vector<char>(6, '.'));

    for (int i = 0; i < 12; i++) {
        cin >> input;
        for (int j = 0; j < 6; j++)
            board[i][j] = input[j];
    }
    int result = 0; //연쇄
    while (true) {
        set<int> bomb = findBomb(); //터지게 될 뿌요의 인덱스
        if (bomb.empty()) //터질 뿌요가 없으면 break
            break;
        result++;
        changeBoard(bomb); //뿌요 터뜨림
    }
    cout<<result;
}