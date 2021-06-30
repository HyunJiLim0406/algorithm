#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> disc;

void rotate(int idx, int d, int amount) {
    vector<int> arr;
    amount %= M; //ex)M=5일 때 6칸 돌린 결과는 1번 돌리는 것과 같음
    int cur = (d) ? amount : M - amount; //반시계 방향 : 시계 방향
    while (arr.size() < M) { //시작점부터 순서대로 벡터에 넣어주기
        arr.push_back(disc[idx][cur]);
        cur = (cur + 1) % M;
    }
    for (int i = 0; i < M; i++)  //벡터에 넣은 값 배열에 넣기
        disc[idx][i] = arr[i];
}

pair<int, int> eraseNum() {
    int sum = 0, cnt = 0; //이번에 지워진 숫자의 총합과 개수
    vector<vector<bool>> is_same(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i < N - 1 && disc[i][j] == disc[i + 1][j]) { //독립된 원판끼리 인접(같은 열)
                is_same[i][j] = true;
                is_same[i + 1][j] = true;
            }
            if (disc[i][j] == disc[i][(j + 1) % M]) { //같은 원판 내에서 인접(같은 행)
                is_same[i][j] = true;
                is_same[i][(j + 1) % M] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (disc[i][j] && is_same[i][j]) { //원판에 숫자가 있었고(0이 아니고), 지워질 예정이라면
                cnt++; //지워진 숫자의 수 증가
                sum += disc[i][j]; //지워진 숫자의 합 증가
                disc[i][j] = 0; //0으로 갱신
            }
        }
    }
    return make_pair(sum, cnt);
}

int changeNum(int tot_sum, int tot_cnt) {
    int sum = 0; //변화된 숫자의 합
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (disc[i][j] * tot_cnt > tot_sum) { //평균보다 클 때
                sum--;
                disc[i][j]--;
            }
            else if (disc[i][j] && disc[i][j] * tot_cnt < tot_sum) { //평균보다 작을 때(0보다 커야함)
                sum++;
                disc[i][j]++;
            }
        }
    }
    return sum;
}

int main() {
    int T, x, d, k, tot_sum = 0, tot_cnt;

    cin >> N >> M >> T;
    tot_cnt = N * M; //원판에 써있는 숫자의 개수
    disc.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> disc[i][j];
            tot_sum += disc[i][j]; //원판 숫자의 총합
        }
    }
    for (int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        for (int j = 0; j < N; j++) {
            if ((j + 1) % x == 0) //배수면 돌리기
                rotate(j, d, k);
        }
        pair<int, int> erase_result = eraseNum(); //인접한 숫자 지우기
        if (erase_result.first == 0) //지워진 숫자가 없다면
            tot_sum += changeNum(tot_sum, tot_cnt);
        tot_sum -= erase_result.first;
        tot_cnt -= erase_result.second;
    }
    cout << tot_sum;
}