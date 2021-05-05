#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char order_list[10];
map<string, bool> m;
int max_cnt;
vector<string> most_order;

int cntOrder(string target, vector<string> orders) {
    int cnt = 0;
    for (int i = 0; i < orders.size(); i++) {
        bool isFound = true;
        for (int j = 0; j < target.size(); j++) { //없는 주문이면 다음으로
            if (orders[i].find(target[j]) == string::npos) {
                isFound = false;
                break;
            }
        }
        if (isFound) //있는 주문이면 cnt 증가
            cnt++;
    }
    return cnt;
}

void backtracking(int len, int end, int idx, string order, vector<string> orders) {
    if (len == end) {
        vector<char> tmp; //임시 배열에 넣고 정렬
        for (int i = 0; i < len; i++)
            tmp.push_back(order_list[i]);
        sort(tmp.begin(), tmp.end());
        string str(tmp.begin(), tmp.end());
        if (!m[str]) { //탐색한 메뉴가 아니라면
            m[str] = true;
            int order_cnt = cntOrder(str, orders); //이 메뉴 몇 명이나?
            if (order_cnt > 1) { //1명 이상이고
                if (order_cnt > max_cnt) { //최댓값보다 클 때
                    most_order.clear(); //이전 최댓값 입력 삭제하고 새로 입력
                    max_cnt = order_cnt;
                    most_order.push_back(str);
                } else if (order_cnt == max_cnt) //최댓값과 같을 때 그냥 투입
                    most_order.push_back(str);
            }
        }
        return;
    }
    for (int i = idx + 1; i < order.size(); i++) { //조합만들기
        order_list[len] = order[i];
        backtracking(len + 1, end, i, order, orders);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) { //각각의 코스에 대해
        max_cnt = 0;
        most_order.clear();
        for (int j = 0; j < orders.size(); j++) { //각 주문 별로 백트래킹
            if (orders[j].size() >= course[i]) {
                backtracking(0, course[i], -1, orders[j], orders);
            }
        }
        for (int i = 0; i < most_order.size(); i++) //해당 코스의 가장 많이 주문된 메뉴 투입
            answer.push_back(most_order[i]);
    }
    sort(answer.begin(), answer.end()); //정렬
    return answer;
}

int main() {
    vector<string> v = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4});
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}