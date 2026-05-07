#include <bits/stdc++.h>
#define ll long long

using namespace std;

void bfs(vector<vector<int>>& adj){
    int cont=0, n=adj.size()-1;
    if(n==0) return;
    vector<bool> visitado(n+1, false);
    queue<int> q;
    q.push(1);
    visitado[1]=true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cont++;
        for(int v : adj[u]){
            if(!visitado[v]){
                visitado[v]=true;
                q.push(v);
            }
        }
    }
    if(cont==n) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m,u,v;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);


    
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m!=n-1) cout<<"NO\n"; //ou tem ciclo ou é desconexo
    else if(n==1&&m==0) cout<<"YES\n";
    else bfs(adj);
}