#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> schedule, multi_tap;
vector<vector<int>> idx_table;

int findPos(int idx, int start, int K) {
    int result = K + 1; //초기화
    for (int i = 0; i < idx_table[idx].size(); i++) {
        if (idx_table[idx][i] > start) { //현재 위치보다 오른쪽에서 처음으로 사용되는 위치
            result = idx_table[idx][i];
            break;
        }
    }
    return result;
}

int scheduling(int N, int K) {
    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (find(multi_tap.begin(), multi_tap.end(), schedule[i]) != multi_tap.end()) //이미 꽂혀 있음
            continue;
        if (multi_tap.size() < N) //멀티탭에 공간이 있음
            multi_tap.push_back(schedule[i]);
        else { //뽑아야 함
            cnt++;
            int idx = 0, pos = 0; //뽑을 전자기기의 멀티탭 인덱스, 가장 늦게 쓰이는 전자기기의 사용 위치
            for (int j = 0; j < N; j++) {
                int tmp = findPos(multi_tap[j], i, K); //전자기기의 사용 위치 계산
                if (tmp > pos) { //제일 늦게 사용되는 전자기기라면 갱신
                    pos = tmp;
                    idx = j;
                }
            }
            multi_tap[idx] = schedule[i]; //멀티탭 변경
        }
    }
    return cnt;
}

int main() {
    int N, K;

    cin >> N >> K;
    schedule.assign(K, 0);
    idx_table.assign(K + 1, vector<int>(0));
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
        idx_table[schedule[i]].push_back(i); //각 전자기기의 사용 위치 저장
    }
    cout<<scheduling(N, K);
}