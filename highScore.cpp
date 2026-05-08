#include <bits/stdc++.h>
#define ll long long
#define inf 4e18

using namespace std;

int a,b;
ll w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> edge;
    vector<vector<int>> rev(n+1);
    vector<ll> dist(n+1,inf);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edge.push_back({a,b,-w});//é menos pq ai minimiza custo aumentando o score
        rev[b].push_back(a);//grafo ao contrario
    }
    vector<bool> caminho(n+1,false);
    queue<int> q;
    q.push(n);
    caminho[n] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : rev[u]){
            if(!caminho[v]){
                caminho[v] = true;
                q.push(v);
            }
        }
    }
    dist[1] = 0;

    for(int i = 1; i <= n - 1; i++){
        for(auto e : edge){
            ll a=e[0]; ll b=e[1]; ll w=e[2];
            if(dist[a] == inf) continue;
            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
            }
        }
    }

    for(auto e : edge){
        ll a=e[0]; ll b=e[1]; ll w=e[2];
        if(dist[a] == inf) continue;
        if(dist[a] + w < dist[b] && caminho[b]){
                cout<<"-1\n";
                return 0;
            }
    }
    cout<<-dist[n]<<"\n";
}