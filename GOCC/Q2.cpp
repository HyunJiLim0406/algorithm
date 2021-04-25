#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> v; //input 벡터
vector<pair<int, int>> p; //2개의 쌍 벡터. first = 둘의 xor 값, second = 사용한 idx 표시
int N;
int min_sum = -1, max_sum = 0;

void backtracking(int cur, int idx, int num) {
    if (cur == ((1 << N) - 1)) { //N=4라면 1111 됐을 때 전부 찾은 것
        if (min_sum == -1)
            min_sum = num;
        min_sum = min(min_sum, num);
        max_sum = max(max_sum, num);
        return;
    }
    for (int i = idx + 1; i < p.size(); i++) {
        if ((cur ^ p[i].second) == (cur | p[i].second)) { //둘의 xor 연산과 or 연산의 값이 같아야 중복 X
            num += p[i].first; //visited
            backtracking(cur | p[i].second, i, num);
            num -= p[i].first; //unvisited
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    for (int i = 0; i < v.size() - 1; i++) { //2개씩 묶어서 만들기
        for (int j = i + 1; j < v.size(); j++)
            p.push_back(make_pair(v[i] ^ v[j], (1 << i) | (1 << j)));
    }
    backtracking(0, -1, 0);
    cout << min_sum << ' ' << max_sum;
}