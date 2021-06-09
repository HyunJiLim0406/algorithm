#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        vector<pair<int, int>> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(), arr.end()); //서류심사 성적으로 오름차순 정렬
        int cur = arr[0].second; //이것보단 면접심사 성적이 좋아야 함
        int cnt = 1; //뽑힐 수 있는 사람의 수
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i].second < cur) { //갱신
                cur = arr[i].second;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}