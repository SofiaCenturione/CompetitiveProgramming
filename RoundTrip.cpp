#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int> adj[MAX];
int pai[MAX],visitado[MAX],ciclo_ini,ciclo_fim;

bool dfs(int u,int p){
    visitado[u]=1;
    pai[u]=p;
    for(int v : adj[u]){
        if(v==p) continue; //para não volta pelo caminho que veio
        if(visitado[v]==1){//encontrou ciclio
            ciclo_ini = v;
            ciclo_fim = u;
            return true;
        }
        if(visitado[v]==0){
            if(dfs(v, u)) return true;
        }
    }
    visitado[u]=2;
    return false;
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
        if(visitado[i]==0){
            if(dfs(i,-1)){
                //encontrou ciclo então tem q reconstruir o caminho
                vector<int> caminho;
                caminho.push_back(ciclo_ini);
                for(int atual=ciclo_fim; atual!=ciclo_ini; atual=pai[atual]){
                    caminho.push_back(atual);
                }
                caminho.push_back(ciclo_ini);
                cout<<caminho.size()<<"\n";
                for(int j=0;j<caminho.size();j++){
                    cout<<caminho[j]<<(j == caminho.size() - 1 ? "" : " ");
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}