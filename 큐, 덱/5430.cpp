#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string p, arr;
    int T, n;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> p >> n;
        deque <int> dq;
        cin >> arr;
        string temp; //2자리 이상일 때
        for (int j = 0; j < arr.length(); j++) {
            if ('0' <= arr[j] && arr[j] <= '9') //숫자면 저장
                temp += arr[j];
            else if (arr[j] == ',' || arr[j] == ']') { //쉼표나 괄호 만나면 전부 빼냄
                if (!temp.empty()) {
                    dq.push_back(stoi(temp)); //stoi 쓰려면 c++11로 써야함
                    temp.clear();
                }
            }
        }
        bool isError = false; //에러확인
        bool isFront = true; //reverse 확인
        for (int j = 0; j < p.length(); j++) {
            if (p[j] == 'R') { //현재 상태에서 reverse
                if (isFront)
                    isFront = false;
                else
                    isFront = true;
            }
            else if (p[j] == 'D') {
                if (dq.empty()) { //덱이 비어 있으면 에러
                    cout << "error\n";
                    isError = true;
                    break;
                }
                else if (isFront) //reverse 상태에 따라 pop
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (!isError) {
            cout << "[";
            if (isFront) { //앞에서부터 출력
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty())
                        cout << ",";
                }
            }
            else { //뒤에서부터 출력
                while (!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())
                        cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}