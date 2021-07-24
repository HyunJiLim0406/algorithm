#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info { //내구도와 로봇 존재 여부
    int durability;
    bool is_on;
};

vector<info> belt;
queue<int> robot;

void moveRobot(int head, int N) {
    int size = robot.size(), end = (head + N - 1) % (2 * N);;
    while (size--) {
        int cur = robot.front(); //현재 로봇의 위치
        robot.pop();

        if (cur == end) //내려야하는 로봇
            continue;
        int next = (cur + 1) % (2 * N); //다음 위치
        if (belt[next].durability && !belt[next].is_on) { //다음 위치의 내구도가 남아있고, 로봇이 없을 때
            belt[cur].is_on = false;
            belt[next].durability--;
            if (next != end) { //다음 위치가 내리는 곳이 아니라면
                belt[next].is_on = true;
                robot.push(next);
            }
        } else //로봇 이동 불가
            robot.push(cur);
    }
}

bool isFin(int K, int size) { //내구도가 0인 칸이 몇개인지 계산
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (!belt[i].durability)
            cnt++;
    }
    return cnt >= K;
}

int main() {
    int N, K, size;

    cin >> N >> K;
    size = N * 2;
    belt.assign(size, {0, false});
    for (int i = 0; i < size; i++)
        cin >> belt[i].durability;

    int head = 0, step = 1;
    while (true) {
        head = (head + size - 1) % size; //벨트 이동
        belt[(head + N - 1) % size].is_on = false; //내리는 위치에 로봇이 있는지 확인
        moveRobot(head, N); //로봇들 이동
        if (belt[head].durability) { //로봇 올리기
            belt[head].durability--;
            belt[head].is_on = true;
            robot.push(head);
        }
        if (isFin(K, size)) //종료되는지 확인
            break;
        step++;
    }
    cout << step;
}