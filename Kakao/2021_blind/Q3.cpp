#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> makeList(vector<string> str) { //리스트 화
    vector<vector<string>> result;
    for (int i = 0; i < str.size(); i++) {
        str[i] += ' '; //맨 뒤에 띄어쓰기 추가
        string tmp = "";
        vector<string> list;
        for (int j = 0; j < str[i].size(); j++) {
            if (str[i][j] == ' ') { //띄어쓰기라면
                if (tmp.compare("and") != 0) //tmp의 값이 and가 아닐 때
                    list.push_back(tmp); //리스트에 tmp 추가
                tmp.clear(); //tmp 초기화
            } else //문자면 tmp에 입력
                tmp += str[i][j];
        }
        result.push_back(list);
    }
    return result;
}

bool isPromising(vector<string> q, vector<string> io) {
    for (int i = 0; i < q.size() - 1; i++) { //q[i]가 -가 아닌데 io[i]와 다르다면 false
        if ((q[i] != "-") && (q[i].compare(io[i]) != 0))
            return false;
    }
    if (stoi(q[q.size() - 1]) <= stoi(io[io.size() - 1])) //점수 확인
        return true;
    return false;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> infos = makeList(info);
    vector<vector<string>> queries = makeList(query);
    for (int i = 0; i < queries.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < infos.size(); j++) {
            if (isPromising(queries[i], infos[j]))
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

//효율성 통과 X
int main() {
    vector<int> v = solution({"java backend junior pizza 150", "python frontend senior chicken 210",
                              "python frontend senior chicken 150", "cpp backend senior pizza 260",
                              "java backend junior chicken 80", "python backend senior chicken 50"},
                             {"java and backend and junior and pizza 100",
                              "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250",
                              "- and backend and senior and - 150", "- and - and - and chicken 100",
                              "- and - and - and - 150"});
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
}