/**미로 탐색 / 실버1 / 2178*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector< vector<char> > v(101, vector<char>(101, 0));
vector< vector<int> > mark(101, vector<int>(101, 0));

struct Point{
    int x;
    int y;
    int dist; //거리
};

int bfs(){

    queue<Point> q;
    q.push((Point){1, 1, 1});

    while(!q.empty()){

        Point p = q.front();
        q.pop();
        int x = p.x;
        int y = p.y;
        int dist = p.dist;
        
        if(x == n && y == m) return dist;
    

        if(x>1 && v[x-1][y]=='1' && mark[x-1][y]==0){
            q.push((Point){x-1, y, dist+1});
            mark[x-1][y] = 1;
        }
        if(y>1 && v[x][y-1]=='1' && mark[x][y-1]==0){
            q.push((Point){x, y-1, dist+1});
            mark[x][y-1] = 1;
        }
        if(x<n && v[x+1][y]=='1' && mark[x+1][y]==0){
            q.push((Point){x+1, y, dist+1});
            mark[x+1][y] = 1;
        }
        if(y<m && v[x][y+1]=='1' && mark[x][y+1]==0){
            q.push((Point){x, y+1, dist+1});
            mark[x][y+1] = 1;
        }
    }

    return -1;
}

int main(){
    int result = 0;
    cin >> n >> m;

    for(int i=1; i<=n; i++) //1,1에서 시작
        for(int j=1; j<=m; j++)
            cin >> v[i][j];

    mark[1][1] = 1;
    result = bfs();
    cout << result;
    return 0;
}