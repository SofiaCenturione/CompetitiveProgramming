#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> adj[1005];
bool visi[1005], gov[1005];

int bfs(int ini){
    queue<int> q;
    q.push(ini);
    visi[ini]=true;
    int sz=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        sz++;
        for(int v:adj[u]){
            if(!visi[v]){
                visi[v]=true;
                q.push(v);
            }
        }
    }
    return sz;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> governos(k);
    vector<int> componentes;
    for(int i=0;i<k;i++)
    {
        cin>>governos[i];
        gov[governos[i]]=true;
    }
    int u,v,usado=0,mtamanho=0,indice=0;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int g:governos) { //componentes com governos
        if(!visi[g]){
            int sz=bfs(g);
            componentes.push_back(sz);
        }
    }
    for(int i=0;i<(int)componentes.size();i++){//maior componente
        usado+=componentes[i];
        if(componentes[i]>mtamanho){
            mtamanho=componentes[i];
            indice=i;
        }
    }

    // componentes sem governo
    int aux=n-usado;
    componentes[indice]+=aux;
    ll maxi=0;

    for(int sz:componentes){
        maxi+= 1LL *sz*(sz-1)/2;
    }

    cout<<maxi-m<<"\n";
}