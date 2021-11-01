#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci;

vector<vector<ci>> parent;

ci findParent(int row, int col) {
    if (parent[row][col].first < 0) //루트
        return {row, col};
    return parent[row][col] = findParent(parent[row][col].first, parent[row][col].second); //트리 압축하면서 부모 찾기
}

void unionInput(int xr, int xc, int yr, int yc) {
    ci xp = findParent(xr, xc);
    ci yp = findParent(yr, yc);

    if (xp == yp) //이미 같은 집합
        return;
    //나중에 포인터로 수정
    if (parent[xp.first][xp.second].first < parent[yp.first][yp.second].first) {
        parent[xp.first][xp.second].first += parent[yp.first][yp.second].first;
        parent[yp.first][yp.second] = xp;
    } else {
        parent[yp.first][yp.second].first += parent[xp.first][xp.second].first;
        parent[xp.first][xp.second] = yp;
    }
}

int main() {
    int n, m;
    string input;

    map<char, pair<int, int>> dir; //방향
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};

    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    parent.assign(n, vector<ci>(m, {-1, 0}));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++)
            board[i][j] = input[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ci d = dir[board[i][j]];
            unionInput(i, j, i + d.first, j + d.second); //가능한 모든 쌍 유니온 파인드
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (parent[i][j].first < 0) //루트라면
                ans++;
        }
    }
    cout << ans;
}