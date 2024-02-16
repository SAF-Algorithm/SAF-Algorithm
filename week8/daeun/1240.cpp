/**노드사이의 거리 / 골드5 / 1240*/
#include <vector>
#include <iostream>

using namespace std;
int n, m;
vector< vector<pair<int, int> > > graph(1001);

int dfs(int start, int end, vector<int> &mark){
    if(start == end) return 0;

    mark[start] = 1;

    for(int i = 0; i<graph[start].size(); i++){
        pair<int, int> p = graph[start][i];
        int next = p.first; //연결된 노드 번호
        int distance = p.second; //두 노드 사이의 거리

        if(mark[next]==0){
            //연결된 노드를 방문하지 않았다면
            int result = dfs(next, end, mark);
            if(result != -1) return result + distance;
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<n; i++){ //1부터 시작
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a].emplace_back(b, weight); //pair 응용
        graph[b].emplace_back(a, weight);
    }

    vector<int> result(m, 0);

    while(m-- > 0){
        int start, end;
        cin >> start >> end;

        vector<int> mark(n+1, 0);
        int result = dfs(start, end, mark);
        cout << result << "\n";
    }
    return 0;
}