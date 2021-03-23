#include <iostream>
#include <algorithm>
using namespace std;

struct meeting {
    int start_time, end_time;
};
meeting* m = new meeting[100001];

bool cmp(const meeting& m1, const meeting& m2) {
    if (m1.end_time < m2.end_time) //빨리 끝나는게 앞으로
        return true;
    else if (m1.end_time == m2.end_time) //끝나는 시간 같다면 먼저 시작하는걸 앞에
        return m1.start_time < m2.start_time;
    else
        return false;
}

int meetings(int N) {
    int end_time = 0, cnt = 0;

    for (int i = 0; i < N; i++) {
        if (m[i].start_time >= end_time) { //이전 회의가 끝난 뒤 시작하는 거라면
            end_time = m[i].end_time; //끝나는 시간 초기화
            cnt++; //가능 회의 증가
        }
    }
    return cnt;
}

int main() {
    int N, last_time = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> m[i].start_time >> m[i].end_time;
    sort(m, m + N, cmp); //정렬
    cout << meetings(N);
}