#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int> adj[MAX];
int timea[MAX]; 

bool bfs(int ini){
    queue<int> q;
    q.push(ini);
    timea[ini] = 1; 
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : adj[u]){
            if(timea[v]==0){
                timea[v]=(timea[u]==1) ? 2 : 1;//se não tem time coloca no time oposto
                q.push(v);
            } 
            else if(timea[v]==timea[u]){
                return false;//amigo já tem o mesmo time então é impossível
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(timea[i]==0){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++) 
        cout<<timea[i]<<(i == n ? "" : " ");
    cout<<"\n";
}