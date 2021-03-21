#include <iostream>
using namespace std;
#define DIVISOR 1000000000

int dp[101][10]; //n번째의 0~9의 개수를 저장함

int easy_stair(int num) { //뭐 더할 일 있을 때마다 계속 나눠줌
    int result = 0;
    for (int i = 0; i < 10; i++) { //시작점 초기화
        if (i == 0)
            dp[1][i] = 0;
        else
            dp[1][i] = 1;
    }
    for (int i = 2; i <= num; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) //0인 경우는 1에서 건너오는 것
                dp[i][j] = dp[i - 1][j + 1] % DIVISOR;
            else if (j == 9) //9인 경우는 8에서 건너오는 것
                dp[i][j] = dp[i - 1][j - 1] % DIVISOR;
            else //나머지는 이전, 이후 더해줌. ex) 3이면 이전 상황의 2와 4의 개수를 합쳐줌
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIVISOR;
        }
    }
    for (int i = 0; i < 10; i++) {
        result += dp[num][i];
        result %= DIVISOR; //더하는 도중에도 계속 나눠줘야 함
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    cout << easy_stair(N) << '\n';
}