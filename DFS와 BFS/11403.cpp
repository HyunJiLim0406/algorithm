#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<vector<int>> connected;

void dfs(int start, int cur){
    for(int i=0;i<graph[cur].size();i++){
        if(!visited[graph[cur][i]]) {
            connected[start][graph[cur][i]] = 1; //연결 처리
            visited[graph[cur][i]] = true; //start를 미방문 처리하기 위해 방문 처리를 여기서 하는 것
            dfs(start, graph[cur][i]);
        }
    }
}

int main(){
    int N, input;

    cin>>N;
    graph.assign(N, vector<int>(0));
    connected.assign(N, vector<int>(N, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>input;
            if(input==1)
                graph[i].push_back(j);
        }
    }
    for(int i=0;i<N;i++){ //모든 정점에 대해 dfs
        visited.assign(N, false);
        dfs(i, i);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<connected[i][j]<<' ';
        cout<<'\n';
    }
}