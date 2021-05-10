#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    map<string, int> name; //이름 - 숫자
    map<int, string> number; //숫자 - 이름
    string input;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        name[input] = i;
        number[i] = input;
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (isdigit(input[0])) //숫자인지 확인
            cout<<number[stoi(input)]<<'\n';
        else
            cout << name[input] << '\n';
    }
}