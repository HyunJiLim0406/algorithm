#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int diff(vector<int> &s, vector<int> &d) {
    int cnt = 0, i1 = 0, i2 = 0;
    while (i1 < s.size() && i2 < d.size()) {
        if (s[i1] == d[i2]) { //공통 원소
            i1++;
            i2++;
        } else if (s[i1] > d[i2]) //d의 다음 원소 살펴보기
            i2++;
        else if (s[i1] < d[i2]) { //s의 이번 원소와 일치하는 원소 없음
            cnt++;
            i1++;
        }
    }
    return cnt + (s.size() - i1); //남아있는 s의 원소들 더하기
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end()); //정렬
    sort(b.begin(), b.end()); //정렬
    cout << diff(a, b) + diff(b, a);
}