#include <bits/stdc++.h>
using namespace std; 
#define MAX 100005

vector<int> adj[MAX];//guardando arestas, lista de adjacencia(melhor q a matriz)
int parent[MAX]; //no anterior de caminho mais curto
bool visitou[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visitou[1]=true;
    parent[1]=0; 
    bool possivel=false;
    while(!q.empty()){
        int atual=q.front();
        q.pop();
        if(atual==n){
            possivel=true;
            break;
        }

        for(int neighbor : adj[atual]){
            if(!visitou[neighbor]){
                visitou[neighbor]=true;
                parent[neighbor]=atual;
                q.push(neighbor);
            }
        }
    }

    if(!possivel) cout<<"IMPOSSIBLE\n";
    else {
        vector<int> caminho;
        //faz o caminho do fim para o começo
        for(int v=n;v!=0;v=parent[v])
            caminho.push_back(v);
        reverse(caminho.begin(), caminho.end());
        cout<<caminho.size()<<"\n";
        for(int i=0;i<caminho.size();i++){
            cout<<caminho[i]<<(i == caminho.size() - 1 ? "" : " ");
        }
        cout<<"\n";
    }
}