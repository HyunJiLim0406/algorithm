#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, money, result;
vector<pair<int, int>> input;

void backtracking(int idx) {
    if (money > result) //최대 비용 비교
        result = money;
    for (int i = idx; i < N; i++) {
        if ((input[i].first + i) <= N) { //상담 가능
            money += input[i].second; //visited 처리
            backtracking(input[i].first + i);
            money -= input[i].second; //unvisited 처리
        }
    }
}

int main() {
    int dur, profit;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dur >> profit;
        input.push_back(make_pair(dur, profit));
    }
    backtracking(0);
    cout << result;
}