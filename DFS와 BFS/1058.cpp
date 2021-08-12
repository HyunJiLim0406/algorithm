#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> friends;

void fillFriend(int N, int idx) { //친구와 친구의 친구를 다르게 표시해야 함
    for (int i = 0; i < N; i++) {
        if (friends[idx][i] == 1) { //친구
            for (int j = 0; j < N; j++) { //친구의 친구
                if (friends[i][j] == 1 && !friends[idx][j] && j != idx)
                    friends[idx][j] = 2;
            }
        }
    }
}

int cntFriends(int N, int idx) { //2-친구 수 찾기
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (friends[idx][i])
            result++;
    }
    return result;
}

int main() {
    int N;
    string input;

    cin >> N;
    friends.assign(N, vector<int>(N, false));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            if (input[j] == 'Y')
                friends[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++)
        fillFriend(N, i);
    int result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, cntFriends(N, i));
    cout << result;
}