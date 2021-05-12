#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pp;

int N, min_dist = 1e9;
vector<vector<int>> map; //지도
vector<vector<pp>> chicken_dist; //각 가정집과 치킨집 사이의 거리
vector<pp> chicken_pos, house_pos; //치킨집, 가정집 위치

int calcDist(int idx) {
    for (int i = 0; i < chicken_dist[idx].size(); i++) { //거리가 가장 짧은 치킨집부터
        pp chicken = chicken_pos[chicken_dist[idx][i].second];
        if (map[chicken.first][chicken.second] == 2) //남아있는 치킨집이라면 바로 리턴
            return chicken_dist[idx][i].first;
    }
    return -1;
}

void backtracking(int idx, int cnt, int target) { //폐점할 치킨집을 고르는 백트래킹
    if (cnt == target) { //치킨집을 전부 고르면
        int city_dist = 0; //도시의 치킨 거리
        for (int i = 0; i < house_pos.size(); i++) //모든 집에 대해 가장 짧은 치킨 거리 구하기
            city_dist += calcDist(i);
        min_dist = min(min_dist, city_dist); //최솟값 갱신
        return;
    }
    for (int i = idx + 1; i < chicken_pos.size(); i++) { //모든 치킨집에 대해
        pp cur_pos = chicken_pos[i];
        map[cur_pos.first][cur_pos.second] = 0; //visited 처리
        backtracking(i, cnt + 1, target);
        map[cur_pos.first][cur_pos.second] = 2; //unvisited 처리
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;

    cin >> N >> M;
    map.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) //가정집 위치 저장
                house_pos.push_back(make_pair(i, j));
            else if (map[i][j] == 2) //치킨집 위치 저장
                chicken_pos.push_back(make_pair(i, j));
        }
    }
    chicken_dist.assign(house_pos.size(), vector<pp>(chicken_pos.size()));
    for (int i = 0; i < house_pos.size(); i++) { //모든 집 - 모든 치킨집 사이의 거리 저장
        pp cur_house = house_pos[i];
        for (int j = 0; j < chicken_pos.size(); j++) {
            pp cur_chicken = chicken_pos[j];
            chicken_dist[i][j] = make_pair(
                    abs(cur_house.first - cur_chicken.first) + abs(cur_house.second - cur_chicken.second), j);
        }
    }
    for (int i = 0; i < chicken_dist.size(); i++) //오름차순 정렬
        sort(chicken_dist[i].begin(), chicken_dist[i].end());
    int target = chicken_pos.size() - M; //폐점해야 할 치킨집의 수
    backtracking(-1, 0, target);
    cout << min_dist;
}