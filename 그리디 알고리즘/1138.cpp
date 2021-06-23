#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, input;

    cin >> N;
    vector<int> result(N, 0);
    for (int i = 1; i <= N; i++) {
        cin >> input;
        int cnt = 0;
        for (int j = 0; j < N; j++) { //왼쪽에 있는 0의 개수가 input개인 j를 찾기
            if (result[j]) //이미 사람이 있음(나보다 작은 사람)
                continue;
            if (cnt == input) { //본인의 자리
                result[j] = i;
                break;
            }
            cnt++;
        }
    }
    for (int i = 0; i < N; i++)
        cout << result[i] << ' ';
}