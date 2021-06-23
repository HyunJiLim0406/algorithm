#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(string init, int init_pos) {
    map<string, int> dist; //최단 경로
    queue<pair<string, int>> q;
    dist[init] = 1; //초기화
    q.push(make_pair(init, init_pos));
    while (!q.empty()) {
        string str = q.front().first; //상태
        int pos = q.front().second; //0의 위치
        int cur_dist = dist[str]; //경로
        q.pop();

        if (str == "123456780") //종료 조건
            return dist[str] - 1;
        int row = pos / 3; //행
        int col = pos % 3; //열
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= 3) || (nc < 0) || (nc >= 3)) //범위 내에 있다면
                continue;
            int np = nr * 3 + nc; //새로운 0의 위치
            swap(str[pos], str[np]); //위치 변경
            if (!dist[str]) { //미방문 상태
                dist[str] = cur_dist + 1;
                q.push(make_pair(str, np));
            }
            swap(str[pos], str[np]); //위치 복구
        }
    }
    return -1;
}

int main() {
    int input, init_pos;
    string init = "";

    for (int i = 0; i < 9; i++) {
        cin >> input;
        if (input == 0) //0의 위치
            init_pos = i;
        init += to_string(input);
    }
    cout << bfs(init, init_pos);
}