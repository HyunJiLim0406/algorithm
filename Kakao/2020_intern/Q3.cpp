#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> gem;
int gem_cnt;

vector<int> minLen(vector<string> gems) {
    vector<int> result;
    int res_left, res_right, min_len = 100001;
    int left = 0, right = 0;

    gem[gems[0]] = 1;
    while ((left < gems.size()) && (right < gems.size())) { //범위 내에 있을 때
        if (gem.size() == gem_cnt) { //모든 보석이 있음
            if ((right - left) < min_len) { //원래의 최소길이보다 짧다면 갱신
                min_len = right - left;
                res_left = left;
                res_right = right;
            }
            gem[gems[left]] -= 1; //보석 삭제
            if (gem[gems[left]] == 0) //0개라면 보석 리스트에서 삭제
                gem.erase(gems[left]);
            left++; //left 포인터 오른쪽으로 이동
        } else { //모든 보석이 없음
            right++; //right 포인터 오른쪽으로 이동
            if (right < gems.size()) //범위 안에 있다면 보석 추가
                gem[gems[right]] += 1;
        }
    }
    result.push_back(res_left + 1);
    result.push_back(res_right + 1);
    return result;
}

vector<int> solution(vector<string> gems) {
    gem_cnt = 0;
    gem.clear();
    map<string, int> init;
    for (int i = 0; i < gems.size(); i++) { //전체 보석의 수
        init[gems[i]] += 1;
        if (init[gems[i]] == 1)
            gem_cnt++;
    }
    vector<int> answer = minLen(gems);
    return answer;
}

int main() {
    cout << solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"})[0] << ' '
         << solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"})[1] << '\n';
    cout << solution({"AA", "AB", "AC", "AA", "AC"})[0] << ' ' << solution({"AA", "AB", "AC", "AA", "AC"})[1] << '\n';
    cout << solution({"XYZ", "XYZ", "XYZ"})[0] << ' ' << solution({"XYZ", "XYZ", "XYZ"})[1] << '\n';
    cout << solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"})[0] << ' '
         << solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"})[1] << '\n';
}