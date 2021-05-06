#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int findPair(int x) { //투 포인터
    int cnt = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) { //둘의 위치가 역전되면 break
        int sum = arr[left] + arr[right];
        if (sum == x) { //x와 같으면 left 증가, right 감소
            cnt++;
            left++;
            right--;
        } else if (sum > x) //x보다 크면 right 감소
            right--;
        else //x보다 작으면 left 증가
            left++;
    }
    return cnt;
}

int main() {
    int N, x;

    cin >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr.begin(), arr.end()); //정렬
    cout << findPair(x);
}
