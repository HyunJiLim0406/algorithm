#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> sign;
bool visited[10];
int k;
long long min_num = 9876543211, max_num = 0;

void backtracking(int pos, string str) {
    if (pos == k) { //부등호 다 쓰면 최대 최소 갱신
        long long result = stol(str);
        min_num = min(min_num, result);
        max_num = max(max_num, result);
        return;
    }

    string saved = str; //unvisited 처리용 기존 str
    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            int last_num = str[str.size() - 1] - '0'; //str의 마지막 원소
            visited[i] = true; //visited 처리
            str += to_string(i);
            if ((sign[pos] == '<') && (last_num < i)) //부등호가 '<'이고 i가 last_num 보다 클 때
                backtracking(pos + 1, str);
            else if ((sign[pos] == '>') && (last_num > i)) //부등호가 '>'이고 i가 last_num 보다 작을 때
                backtracking(pos + 1, str);
            visited[i] = false; //unvisited 처리
            str = saved;
        }
    }
}

int main() {
    char input;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> input;
        sign.push_back(input);
    }
    for (int i = 0; i < 10; i++) { //첫번째 숫자 지정
        visited[i] = true;
        backtracking(0, to_string(i));
        visited[i] = false;
    }
    if (to_string(max_num).size() == k) //첫 자리가 0이면
        cout << 0;
    cout << max_num << '\n';
    if (to_string(min_num).size() == k) //첫 자리가 0이면
        cout << 0;
    cout << min_num << '\n';
}