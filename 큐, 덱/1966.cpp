#include <iostream>
#include <queue>
using namespace std;

struct paper { //우선순위와 체크여부 저장
    int pri;
    bool checked;
};

bool endLoop(queue <paper> q) { //타겟 데이터가 빠지면 루프 종료
    queue <paper> tmp = q;

    while (!tmp.empty()) {
        if (!tmp.front().checked)
            return false;
        tmp.pop();
    }
    return true;
}

bool canPrint(queue <paper> q) { //우선순위 비교하며 프린트 가능여부 확인
    queue <paper> tmp = q;
    int key = tmp.front().pri;

    tmp.pop();
    while (!tmp.empty()) {
        if (key < tmp.front().pri)
            return false;
        tmp.pop();
    }
    return true;
}

int main() {
    int T, N, M;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        queue <paper> q;
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (j == M) //타겟 데이터의 checked를 false로 설정
                q.push({ num, false });
            else
                q.push({ num, true });
        }
        int cnt = 0;
        while (!endLoop(q)) {
            while (!canPrint(q)) { //우선순위가 밀린다면 뒤로 옮겨줌
                paper temp = q.front();
                q.pop();
                q.push(temp);
            }
            q.pop(); //프린트
            cnt++;
        }
        cout << cnt << '\n';
    }
}