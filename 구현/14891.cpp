#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gear(4);

void moveGear(int idx, int dir) {
    string tmp;
    switch (dir) {
        case -1: //시계 반대방향
            tmp = gear[idx].substr(1, 7);
            tmp += gear[idx][0];
            break;
        case 1: //시계 방향
            tmp = gear[idx].substr(0, 7);
            tmp = gear[idx][7] + tmp;
            break;
    }
    gear[idx] = tmp;
}

int calcScore() { //점수 계산
    int score = 0, num = 1;
    for (int i = 0; i < 4; i++) {
        score += (gear[i][0] == '0') ? 0 : num;
        num *= 2;
    }
    return score;
}

int main() {
    int K, num, dir;

    for (int i = 0; i < 4; i++)
        cin >> gear[i];
    cin >> K;
    while (K--) {
        cin >> num >> dir;
        num--; //인덱스 조정
        int start = num, end = num; //바뀌기 시작하는 톱니바퀴, 마지막으로 바뀌는 톱니바퀴

        for (int i = num - 1; i >= 0; i--) { //왼쪽 톱니바퀴 확인
            if (gear[i][2] == gear[i + 1][6])
                break;
            start = i;
        }
        for (int i = num + 1; i < 4; i++) { //오른쪽 톱니바퀴 확인
            if (gear[i][6] == gear[i - 1][2])
                break;
            end = i;
        }
        if (start % 2 != num % 2) //시작 방향 조절
            dir *= -1;
        for (int i = start; i <= end; i++) { //톱니 회전
            moveGear(i, dir);
            dir *= -1;
        }
    }
    cout << calcScore(); //점수 계산
}