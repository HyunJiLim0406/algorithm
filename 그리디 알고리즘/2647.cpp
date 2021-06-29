#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, result = 0;

    cin >> N;
    vector<int> score(N);
    for (int i = 0; i < N; i++)
        cin >> score[i];
    int cur = score[N - 1] - 1; //현재 레벨의 가능한 최대 점수
    for (int i = N - 2; i >= 0; i--) {
        if (score[i] >= cur) //점수를 감소해야 하는 경우
            result += score[i] - cur;
        else //최대 점수 갱신
            cur = score[i];
        cur--;
    }
    cout << result;
}