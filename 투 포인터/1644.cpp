#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> prime;

void eratos(int N) { //에라토스테네스의 체
    vector<bool> isPrime;
    isPrime.assign(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    int line = sqrt(N) + 1;
    for (int i = 2; i <= line; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i < N + 1; i++) { //구한 소수들 벡터에 넣기
        if (isPrime[i])
            prime.push_back(i);
    }
}

int cntPromise(int N) {
    int cnt = 0;
    int left = 0, right = 0; //왼쪽에서 시작

    int sum = prime[left];
    while ((left < prime.size()) && (right < prime.size())) { //범위 내에 있을 떄
        if (sum >= N) { //N 이상이면 left 증가
            if (sum == N) //N과 같으면 cnt 증가
                cnt++;
            sum -= prime[left];
            left++;
        } else { //N 미만이면 right 증가
            if (right < prime.size())
                sum += prime[right + 1];
            right++;
        }
    }
    return cnt;
}

int main() {
    int N;

    cin >> N;
    if (N == 1) { //1인 경우 처리
        cout << 0;
        return 0;
    }
    eratos(N); //소수 구하기
    cout << cntPromise(N);
}