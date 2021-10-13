#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 52;

int charToIdx(char ch) { //문자를 인덱스로
    if (isupper(ch))
        return ch - 'A';
    return (ch - 'a') + 26;
}

char idxToChar(int idx) { //인덱스를 문자로
    if (idx < 26)
        return idx + 'A';
    return (idx - 26) + 'a';
}

void floydWarshall(vector<vector<bool>> &graph) { //플로이드 워셜
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (graph[j][i] && graph[i][k])
                    graph[j][k] = true;
            }
        }
    }
}

vector<string> ansList(vector<vector<bool>> &graph) { //결과 리스트
    vector<string> ans;
    string basic = "a => b";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != j && graph[i][j]) {
                string tmp = basic;
                tmp[0] = idxToChar(i);
                tmp[tmp.size() - 1] = idxToChar(j);
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}

int main() {
    int n;
    string input;
    vector<vector<bool>> graph(SIZE, vector<bool>(SIZE, false));
    for (int i = 0; i < SIZE; i++) //자기 자신
        graph[i][i] = true;

    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, input);
        char f = input[0], b = input[input.size() - 1];
        graph[charToIdx(f)][charToIdx(b)] = true;
    }

    floydWarshall(graph);
    vector<string> ans = ansList(graph);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}