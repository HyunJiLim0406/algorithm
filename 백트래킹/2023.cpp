#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) { //에라토스테네스
        if (num % i == 0)
            return false;
    }
    return true;
}

void backtracking(int num, int cnt, int N) {
    if (cnt == N) { //신기한 소수
        result.push_back(num);
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0 || i == 5) //짝수거나 5면 소수가 될 수 없음
            continue;
        if (isPrime(num * 10 + i))
            backtracking(num * 10 + i, cnt + 1, N);
    }
}

int main() {
    int N;

    cin >> N;
    backtracking(2, 1, N);
    backtracking(3, 1, N);
    backtracking(5, 1, N);
    backtracking(7, 1, N);
    for (auto i:result)
        cout << i << '\n';
}