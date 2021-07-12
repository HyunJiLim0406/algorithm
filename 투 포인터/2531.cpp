#include <iostream>
#include <vector>

using namespace std;

vector<int> belt, sushi;

int chooseSushi(int N, int k, int c) {
    int result = 1; //쿠폰으로 먹은 1개
    sushi[c]++; //쿠폰 초밥
    for (int i = 0; i < k; i++) {
        sushi[belt[i]]++; //먹음
        if (sushi[belt[i]] == 1) //처음 먹으면 종류 더하기
            result++;
    }
    int tmp = result;
    int left = 0, right = k - 1;
    for (int i = 0; i < N; i++) { //슬라이딩 윈도우
        sushi[belt[left]]--; //먹은거 취소
        if (!sushi[belt[left]]) //종류 빼기
            tmp--;
        left = (left + 1) % N;
        right = (right + 1) % N;
        sushi[belt[right]]++; //먹음
        if (sushi[belt[right]] == 1) //종류 더하기
            tmp++;
        result = max(result, tmp); //최댓값 갱신
    }
    return result;
}

int main() {
    int N, d, k, c;

    cin >> N >> d >> k >> c;
    belt.assign(N, 0);
    sushi.assign(d + 1, 0);
    for (int i = 0; i < N; i++)
        cin >> belt[i];
    cout << chooseSushi(N, k, c);
}