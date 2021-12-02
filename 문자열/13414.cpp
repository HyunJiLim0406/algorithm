#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, l;
    string input;
    map<string, int> m;

    cin >> k >> l;
    for (int i = 1; i <= l; i++) { //각 학생들의 신청 순서
        cin >> input;
        m[input] = i;
    }
    vector<pair<string, int>> arr(m.begin(), m.end()); //벡터로 옮기기
    sort(arr.begin(), arr.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) { //순서 기준 정렬
        return p1.second < p2.second;
    });
    for (int i = 0; i < min(k, (int) arr.size()); i++) //수강 인원 미달일 수도 있으니 조건 잘 체크
        cout << arr[i].first << '\n';
}