#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int num, int P) { //다음 수 계산
    int result = 0;
    while (num) {
        int ans = 1;
        for (int i = 0; i < P; i++)
            ans *= (num % 10);
        result += ans;
        num /= 10;
    }
    return result;
}

int main() {
    int A, P;
    vector<int> v;

    cin >> A >> P;
    int cur = A;
    v.push_back(cur);
    while (true) {
        cur = calc(cur, P);
        if (find(v.begin(), v.end(), cur) != v.end()) //처음으로 중복 수가 나오면 break
            break;
        v.push_back(cur);
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) { //중복이었던 수 나올때까지 개수 세기
        if (v[i] == cur)
            break;
        cnt++;
    }
    cout << cnt;
}