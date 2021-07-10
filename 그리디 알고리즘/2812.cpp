#include <iostream>
#include <string>
#include <deque>

using namespace std;

string maxNum(int N, int K, string num) {
    deque<int> dq;
    string result;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front() < num[i] - '0' && cnt < K) { //이번 입력이 dq.front()보다 크면서 아직 K개를 지우지 않았다면
            dq.pop_front(); //dq.front() 지우기
            cnt++; //지워진 숫자 증가
        }
        dq.push_front(num[i] - '0'); //이번 입력 삽입
    }
    while (dq.size() > (N - K)) //충분히 지우지 못했다면 앞에서부터(자릿수가 작은 숫자) 지우기
        dq.pop_front();
    while (!dq.empty()) { //결과
        result += (dq.back() + '0');
        dq.pop_back();
    }
    return result;
}

int main() {
    int N, K;
    string num;

    cin >> N >> K >> num;
    cout << maxNum(N, K, num);
}