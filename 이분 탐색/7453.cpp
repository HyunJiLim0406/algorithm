#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> grouping(vector<int> &v1, vector<int> &v2) { //배열 2개의 가능한 합 조합
    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            result.push_back(v1[i] + v2[j]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> arr(4, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> arr[j][i];
    }
    vector<int> group1 = grouping(arr[0], arr[1]); //A, B 배열
    vector<int> group2 = grouping(arr[2], arr[3]); //C, D 배열
    sort(group2.begin(), group2.end()); //group2만 정렬
    long long cnt = 0;
    for (int i = 0; i < group1.size(); i++) //마이너스를 붙인 수의 개수
        cnt += upper_bound(group2.begin(), group2.end(), -group1[i]) -
               lower_bound(group2.begin(), group2.end(), -group1[i]);
    cout << cnt;
}