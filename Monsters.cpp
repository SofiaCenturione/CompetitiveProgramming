#include <bits/stdc++.h>
using namespace std;
char grid[1000][1000],move_dir[1000][1000],dir_chars[] = {'R', 'L', 'D', 'U'};
int n,m,dist_m[1000][1000],dist_a[1000][1000];
pair<int, int> pai[1000][1000];
int dx[]={0, 0, 1, -1},dy[]={1, -1, 0, 0};

bool valido(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    queue<pair<int, int>> q;
    pair<int, int> comeco;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            dist_m[i][j]=1e9;
            dist_a[i][j]=1e9;
            if(grid[i][j]=='M'){
                q.push({i, j});
                dist_m[i][j]=0;
            } 
            else if(grid[i][j]=='A'){
                comeco={i, j};
            }
        }
    }

    //busca em largura monstro
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(valido(nx, ny) && dist_m[nx][ny]==1e9){
                dist_m[nx][ny]=dist_m[x][y]+1;
                q.push({nx, ny});
            }
        }
    }

    //busca em largura jogador
    q.push(comeco);
    dist_a[comeco.first][comeco.second]=0;
    if (comeco.first==0 || comeco.first==n-1 || comeco.second==0 || comeco.second==m-1){
        cout<<"YES\n0\n"; return 0;
    }

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(valido(nx, ny) && dist_a[nx][ny]==1e9){
                if(dist_a[x][y]+1 <dist_m[nx][ny]){
                    dist_a[nx][ny]=dist_a[x][y]+1;
                    pai[nx][ny]={x, y};
                    move_dir[nx][ny]=dir_chars[i];                    
                    if(nx==0 || nx==n-1 || ny==0 || ny==m-1){
                        cout<<"YES\n";
                        string path="";
                        pair<int, int> atual={nx, ny};
                        while(atual!=comeco){
                            path+=move_dir[atual.first][atual.second];
                            atual=pai[atual.first][atual.second];
                        }
                        reverse(path.begin(), path.end());
                        cout<<path.length()<<"\n"<<path<<"\n";
                        return 0;
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
    cout<<"NO\n";
}