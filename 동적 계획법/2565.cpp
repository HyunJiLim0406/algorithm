#include <iostream>
#include <algorithm>
using namespace std;

struct elec { //source에서 나와서 dest로 들어가는 것
    int source, dest;
};
elec* elecs = new elec[101];
int dp[101] = { 0, };

bool cmp(const elec& e1, const elec& e2) { //source 기준으로 정렬
    if (e1.source < e2.source)
        return true;
    else
        return false;
}

int min_elec(int tot_line) {
    int point = 1; //최대 길이가 나옴
    dp[1] = elecs[1].dest;
    for (int i = 2; i <= tot_line; i++) {
        for (int j = point; j >= 0; j--) {
            if (elecs[i].dest > dp[j]) {
                dp[j + 1] = elecs[i].dest;
                if (j == point)
                    point++;
                break;
            }
        }
    }
    return tot_line - point; //전깃줄 수에서 최대 길이를 빼면 답이 나옴
}

int main() {
    int tot_line;

    cin >> tot_line;
    for (int i = 1; i <= tot_line; i++)
        cin >> elecs[i].source >> elecs[i].dest;
    sort(elecs + 1, elecs + tot_line + 1, cmp); //1부터 시작했으니까 1씩 더해줘야함
    cout << min_elec(tot_line);
}