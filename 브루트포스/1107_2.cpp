#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
vector<int> broken;

bool isChannel(int x) { //채널 이동 가능 여부
    if (x == 0) { //0일 때
        if ((find(broken.begin(), broken.end(), x % 10)) != broken.end())
            return false;
    }
    while (x != 0) { //부서진 버튼이 있으면 안됨
        if ((find(broken.begin(), broken.end(), x % 10)) != broken.end())
            return false;
        x /= 10;
    }
    return true;
}

int length(int x) { //자릿수 계산
    if (x == 0) //0일 때
        return 1;

    int cnt = 0;
    while (x != 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;
        broken.push_back(input);
    }

    int min_click = abs(N - 100); //그냥 +-
    if (M != 10) { //전부 부서진게 아닐 때
        for (int i = 0; i < MAX; i++) {
            if (isChannel(i)) { //갈 수 있는 채널이면
                min_click = min(min_click, abs(N - i) + length(i)); //목표 채널과의 차이 + 자릿수
            }
        }
    }
    cout << min_click;
}