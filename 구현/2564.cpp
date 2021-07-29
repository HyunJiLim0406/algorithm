#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, num, result = 0;

    cin >> N >> M >> num;
    int tot_len = 2 * (N + M);
    vector<pair<int, int>> arr(num);
    pair<int, int> pos;
    for (int i = 0; i < num; i++)
        cin >> arr[i].first >> arr[i].second;
    cin >> pos.first >> pos.second;

    for (int i = 0; i < num; i++) {
        if (arr[i].first == pos.first) //같은 구역
            result += abs(arr[i].second - pos.second);
        else if ((arr[i].first - 1) / 2 == (pos.first - 1) / 2) { //ㄷ자 모양
            int tmp = arr[i].second + pos.second;
            if ((pos.first - 1) / 2 == 0)
                tmp += M;
            else
                tmp += N;
            result += min(tmp, tot_len - tmp);
        } else { //ㄱ자 모양
            if (arr[i].first == 1 && pos.first == 3 || arr[i].first == 3 && pos.first == 1)
                result += (arr[i].second + pos.second);
            else if (arr[i].first == 1 && pos.first == 4)
                result += (N - arr[i].second + pos.second);
            else if (arr[i].first == 4 && pos.first == 1)
                result += (N - pos.second + arr[i].second);
            else if (arr[i].first == 4 & pos.first == 2)
                result += (N - pos.second + M - arr[i].second);
            else if (arr[i].first == 2 && pos.first == 4)
                result += (M - pos.second + N - arr[i].second);
            else if (arr[i].first == 2 && pos.first == 3)
                result += (arr[i].second + M - pos.second);
            else if (arr[i].first == 3 && pos.first == 2)
                result += (M - arr[i].second + pos.second);
        }
    }
    cout<<result;
}