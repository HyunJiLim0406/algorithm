#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> arr_num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, result = 0;
    string input;

    cin >> N >> K;
    if ((K < 5) || (K == 26)) {
        cout << ((K == 26) ? N : 0);
        return 0;
    }
    int init = (1 << ('a' - 'a')) | (1 << ('c' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')); //필수적으로 들어가야 하는 단어
    arr_num.assign(N, init); //초기화
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 4; j < input.size() - 4; j++) { //각 단어를 숫자로 바꿈
            arr_num[i] |= (1 << (input[j] - 'a'));
        }
    }

    for (int i = init; i < (1 << 26); i++) {
        if ((init & i) != init) //init를 포함해야 함
            continue;
        int cnt = 0, local_result = 0;
        for (int j = 0; j < 26; j++) { //단어의 개수 세기
            if (((1 << j) & i) != 0)
                cnt++;
        }
        if (cnt != K) //K개 만큼 있어야 함
            continue;
        for (int j = 0; j < N; j++) {
            if ((arr_num[j] | i) == i) //j번째 단어를 배울 수 있는지 확인
                local_result++;
        }
        result = max(result, local_result); //최댓값 갱신
    }
    cout << result;
}