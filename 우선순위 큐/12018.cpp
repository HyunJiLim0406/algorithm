#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, p, l;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> n >> m;
    while (n--) {
        cin >> p >> l;
        vector<int> arr(p);
        for (int i = 0; i < p; i++)
            cin >> arr[i];
        if (p < l) { //미달
            pq.push(1);
            continue;
        }
        sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
        pq.push(arr[l - 1]); //넣어야하는 최소 마일리지
    }

    int result = 0;
    while (!pq.empty() && pq.top() <= m) { //마일리지가 적게 드는 과목부터 넣기
        m -= pq.top();
        pq.pop();
        result++;
    }
    cout << result;
}