#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int tot_cnt;
string candi[8];

bool isPromising(vector<string> banned_id, vector<string> arr) { //하나의 조합이 순서까지 완벽하게 일치하는지 확인
    int len = banned_id.size();
    for (int i = 0; i < len; i++) {
        if (banned_id[i].size() != arr[i].size()) //길이가 다르면 안됨
            return false;
        for (int j = 0; j < banned_id[i].size(); j++) {
            if ((banned_id[i][j] != '*') && (banned_id[i][j] != arr[i][j])) //*이 아닌데 문자가 다르면 안됨
                return false;
        }
    }
    return true;
}

void backtracking(int len, int idx, vector<string> banned_id, vector<string> user_id) {
    if (len == banned_id.size()) {
        vector<string> tmp_arr; //임시 저장
        for (int i = 0; i < len; i++)
            tmp_arr.push_back(candi[i]);
        sort(tmp_arr.begin(), tmp_arr.end());

        do {
            if (isPromising(banned_id, tmp_arr)) { //가능한 조합이면 tot_cnt 증가
                tot_cnt++;
                return;
            }
        } while (next_permutation(tmp_arr.begin(), tmp_arr.end())); //모든 순서쌍 조회
        return;
    }
    for (int i = idx + 1; i < user_id.size(); i++) { //조합 만들기
        candi[len] = user_id[i];
        backtracking(len + 1, i, banned_id, user_id);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    tot_cnt = 0;
    backtracking(0, -1, banned_id, user_id);
    return tot_cnt;
}

//범위가 작으면 그냥 브루트포스
int main() {
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << '\n';
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"}) << '\n';
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"}) << '\n';
}