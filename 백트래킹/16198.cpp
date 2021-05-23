#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result;
vector<int> energy_marble;

void backtracking(int energy) {
    if (energy_marble.size() == 2) { //배열의 길이가 2라면 최댓값 비교해서 갱신
        result = max(result, energy);
        return;
    }
    for (int i = 1; i < energy_marble.size() - 1; i++) {
        int saved = energy_marble[i]; //삭제할 구슬
        energy += (energy_marble[i - 1] * energy_marble[i + 1]);
        energy_marble.erase(energy_marble.begin() + i); //visited 처리
        backtracking(energy); //백트래킹
        energy_marble.insert(energy_marble.begin() + i, saved); //unvisited 처리
        energy -= (energy_marble[i - 1] * energy_marble[i + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    energy_marble.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> energy_marble[i];
    backtracking(0);
    cout << result;
}