#include <bits/stdc++.h>
#define ll long long

using namespace std;

int conectados(int n, vector<vector<int>>& adj){
    if(n==0) return 0;
    int cont=0;
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
    return cont;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m,u,v;//u v é x y
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n!=m) cout<<"NO\n";
    else{
        int visi=conectados(n,adj);
        if(visi==n) cout<<"FHTAGN!\n";
        else cout<<"NO\n";
    }
}