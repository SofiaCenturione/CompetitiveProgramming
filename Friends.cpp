#include <bits/stdc++.h>
#define ll long long

using namespace std;

int bfs(int ini, vector<bool>& visitado, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(ini);
    visitado[ini]=true;
    int tamanho=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        tamanho++;

        for(int v : adj[u]){
            if(!visitado[v]){
                visitado[v]=true;
                q.push(v);
            }
        }
    }

    return tamanho;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testes, n, m,a, b;
    cin>>testes;
    while(testes--){
        cin>>n>>m;

        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visitado(n+1, false);
        int maior=0;
        for(int i=1;i<=n;i++){
            if(!visitado[i]){
                int tamanho_atual=bfs(i, visitado, adj);//cada vez é um gp de amigo
                if(tamanho_atual>maior) 
                    maior=tamanho_atual;
            }
        }
        cout<<maior<<"\n";
    }
}