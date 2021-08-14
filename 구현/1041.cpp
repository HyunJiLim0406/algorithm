#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ll N, dice[6];

    cin >> N;
    for (int i = 0; i < 6; i++)
        cin >> dice[i];
    ll three = 151; //3개짜리
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (i + j == 5 || j + k == 5 || i + k == 5) //마주보는 변이 없어야 함
                    continue;
                three = min(three, dice[i] + dice[j] + dice[k]);
            }
        }
    }
    ll two = 101; //2개짜리
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j != 5) //마주보는 변이 없어야 함
                two = min(two, dice[i] + dice[j]);
        }
    }
    sort(dice, dice + 6); //정렬
    ll result = 4 * three + (8 * N - 12) * two + (N - 2) * (5 * N - 6) * dice[0]; //N > 1일 때
    if (N == 1) { //N == 1일 때
        result = 0;
        for (int i = 0; i < 5; i++)
            result += dice[i];
    }
    cout << result;
}