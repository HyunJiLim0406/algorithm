#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int result = 0;
    string N;

    cin >> N;
    for (int i = 1; i < N.size(); i++) //N의 자릿수 직전까지
        result += (i * (9 * pow(10, i - 1)));
    int N_num = stoi(N) - pow(10, N.size() - 1) + 1; //N의 자릿수의 개수
    result += N_num * N.size();
    cout << result;
}