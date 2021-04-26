#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//범위 초과 때문에 상하좌우 한줄씩 추가
int matrix[27][27], N, local_cnt;
vector<int> cluster; //각 단지내 집의 수
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> pos) { //같은 단지에 속한 집을 찾는 dfs
    for (int i = 0; i < 4; i++) { //현위치의 상하좌우 좌표를 row, col에 저장
        int row = pos.first + dir[i].first;
        int col = pos.second + dir[i].second;
        if (matrix[row][col] == 1) { //방문한 적 없는 집(leaf)
            local_cnt++; //해당 단지의 집의 수 증가
            matrix[row][col] = 0; //방문 체크
            pair<int, int> next_pos = {row, col};
            dfs(next_pos); //재귀 호출
        }
    }
}

int findHouse() {
    int cnt = 0; //총 단지수

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i][j] == 1) { //방문한 적 없는 집(root)
                cnt++; //총 단지 수 증가
                local_cnt = 1;
                matrix[i][j] = 0;
                pair<int, int> start = {i, j};
                dfs(start); //연결된 모든 집을 찾음
                cluster.push_back(local_cnt); //단지내 집의 수를 저장
            }
        }
    }
    return cnt;
}

int main() {
    string tmp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        for (int j = 1; j <= N; j++)
            matrix[i][j] = tmp[j - 1] - '0';
    }
    cout << findHouse() << '\n'; //총 단지수 출력
    sort(cluster.begin(), cluster.end()); //정렬
    for (int i = 0; i < cluster.size(); i++) //단지별 집의 수 출력
        cout << cluster[i] << '\n';
}