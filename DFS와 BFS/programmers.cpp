#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, vector<string>> graph; //graph[str]의 단어들은 str과 한글자만 다른 단어
map<string, int> dist; //거리 관리

bool cmpString(string str1, string str2) { //연결할 수 있는 단어인지 확인
    int cnt = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i])
            cnt++;
    }
    if (cnt == 1)
        return true;
    return false;
}

int bfs(string begin, string target) {
    queue<string> q;
    dist[begin] = 1; //방문 처리 + 거리
    q.push(begin);
    while (!q.empty()) {
        string cur = q.front();
        int cur_dist = dist[cur];
        q.pop();

        if (cur.compare(target) == 0) //타겟과 일치하면
            return cur_dist - 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (dist[graph[cur][i]] == 0) { //미방문 단어라면 거리 갱신
                dist[graph[cur][i]] = cur_dist + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    return 0; //변환 불가
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin); //begin에 연결된 단어도 체크하기 위해
    for (int i = 0; i < words.size(); i++) {
        vector<string> tmp;
        for (int j = 0; j < words.size(); j++) {
            if (cmpString(words[i], words[j])) //연결가능하면 투입
                tmp.push_back(words[j]);
        }
        graph[words[i]] = tmp;
    }
    int answer = bfs(begin, target);
    return answer;
}

int main() {
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';
}