#include <iostream>
#include <deque>

using namespace std;

int left_move(deque<int> dq, int index) {
    int cnt = 0;
    deque<int> tmp = dq;

    while (tmp.front() != index) {
        int num = tmp.front();
        tmp.pop_front();
        tmp.push_back(num);
        cnt++;
    }
    return cnt;
}

void left_pop(deque<int> *dq, int index) { //포인터로 받아야 제대로 수정됨
    while (dq->front() != index) {
        int num = dq->front();
        dq->pop_front();
        dq->push_back(num);
    }
}

void right_pop(deque<int> *dq, int index) { //포인터로 받아야 제대로 수정됨
    while (dq->front() != index) {
        int num = dq->back();
        dq->pop_back();
        dq->push_front(num);
    }
}

int main() {
    deque<int> dq;
    int N, M, l_cnt, r_cnt, tot_cnt = 0;
    int pos[51];

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> pos[i];
    for (int i = 1; i <= N; i++) {
        bool isPos = false;
        for (int j = 1; j <= M; j++) { //나올 순서에 따라 해당 위치에 1,2,3...입력
            if (i == pos[j]) {
                dq.push_back(j);
                isPos = true;
            }
        }
        if (!isPos)
            dq.push_back(0);
    }
    for (int i = 1; i <= M; i++) {
        l_cnt = left_move(dq, i); //2번 연산
        r_cnt = dq.size() - l_cnt; //3번 연산(덱 사이즈 - 2번 연산 횟수)
        if (l_cnt < r_cnt) { //2번 연산 실제로 수행
            tot_cnt += l_cnt;
            left_pop(&dq, i);
        } else { //3번 연산 실제로 수행
            tot_cnt += r_cnt;
            right_pop(&dq, i);
        }
        dq.pop_front(); //원소 제거
    }
    cout << tot_cnt << '\n';
}