#include <bits/stdc++.h>
using namespace std; 

struct Point {
    int x, y;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direcao[] = {'D', 'U', 'R', 'L'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    Point comeco,fim;
    vector<vector<char>> pathFrom(n, vector<char>(m, 0));
    queue<Point> q;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                comeco={i,j};
            } 
            else if(grid[i][j]=='B'){
                fim={i,j};
            }
        }
    }
    q.push(comeco);
    pathFrom[comeco.x][comeco.y]='S'; 
    bool acho=false;
    while(!q.empty()){
        Point atual=q.front();
        q.pop();
        if(atual.x==fim.x&&atual.y==fim.y){
            acho=true;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=atual.x+dx[i];
            int ny=atual.y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && pathFrom[nx][ny]==0){
                pathFrom[nx][ny]=direcao[i];
                q.push({nx, ny});
            }
        }
    }

    if(acho){
        cout<<"YES\n";
        string path="";
        Point atual=fim;
        //refaz o caminho de trás para frente
        while(atual.x!=comeco.x || atual.y!=comeco.y){
            char move=pathFrom[atual.x][atual.y];
            path+=move;

            //move para a célula anterior
            if(move=='D') atual.x--;
            else if(move=='U') atual.x++;
            else if(move=='R') atual.y--;
            else if(move=='L') atual.y++;
        }

        reverse(path.begin(), path.end());
        cout<<path.length()<<"\n";
        cout<<path<<"\n";
    } 
    else{
        cout<<"NO\n";
    }

}