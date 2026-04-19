#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int> adj[MAX];
bool visitado[MAX];

//busca em profundidade
void dfs(int u){
    visitado[u]=true;
    for(int v : adj[u]){
        if(!visitado[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> repre;
    for(int i=1;i<=n;i++){
        if(!visitado[i]){
            repre.push_back(i);//cidade não visitada, pertence a um novo componente
            dfs(i);
        }
    }
    k=repre.size()-1;
    cout<<k<<"\n";
    for(int i=0;i<k;i++) 
        cout<<repre[i]<<" "<<repre[i+1]<<"\n";
    
}