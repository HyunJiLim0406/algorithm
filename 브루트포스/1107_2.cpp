#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
vector<int> broken;

pair<bool, int> isChannel(int x) { //채널 이동 가능 여부, 자릿수
    int cnt = 0;

    if (x == 0) { //0일 때
        if ((find(broken.begin(), broken.end(), x % 10)) != broken.end())
            return make_pair(false, 0);
        cnt = 1;
    }
    while (x != 0) { //부서진 버튼이 있으면 안됨
        cnt++;
        if ((find(broken.begin(), broken.end(), x % 10)) != broken.end())
            return make_pair(false, 0);
        x /= 10;
    }
    return make_pair(true, cnt);
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
            pair<bool, int> result = isChannel(i);
            if (result.first) { //갈 수 있는 채널이면
                min_click = min(min_click, abs(N - i) + result.second); //목표 채널과의 차이 + 자릿수
            }
        }
    }
    cout << min_click;
}