#include <iostream>
#include <vector>

using namespace std;

int eratos(int size, int pos) {
    vector<bool> is_prime(size + 1, true);
    is_prime[0] = is_prime[1] = false;

    int cnt = 0;
    for (int i = 2; i <= size; i++) { //제곱근까지만 체크하면 안됨. 마지막 숫자가 소수일 때 걔를 지워야 해서
        if (is_prime[i]) { //소수인지 확인
            for (int j = i; j <= size; j += i) {
                if (is_prime[j]) { //중복해서 지우지 않도록 체크
                    is_prime[j] = false;
                    cnt++;
                    if (cnt == pos) //K번째
                        return j;
                }
            }
        }
    }
    return -1;
}

int main() {
    int N, K;

    cin >> N >> K;
    cout << eratos(N, K);
}