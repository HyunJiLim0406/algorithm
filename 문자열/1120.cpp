#include <iostream>
#include <string>

using namespace std;

int diffCnt(string A, string B, int start) {
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[start + i])
            cnt++;
    }
    return cnt;
}

int main() {
    string A, B;
    int result = 51;

    cin >> A >> B;
    for (int i = 0; i <= B.size() - A.size(); i++)
        result = min(result, diffCnt(A, B, i));
    cout << result;
}