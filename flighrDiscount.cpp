#include <bits/stdc++.h>
#define ll long long
#define inf 1e18

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,u,v;
    ll w;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> grafo(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        grafo[u].push_back({v,w});
    }

    vector<vector<ll>> dist(n+1,vector<ll>(2,inf));
    priority_queue<
        tuple<ll,int,int>,
        vector<tuple<ll,int,int>>,
        greater<tuple<ll,int,int>>
    > pq;
    dist[1][0]=0;
    pq.push({0,1,0});

    while(!pq.empty()){
        auto [d, u, usado] = pq.top();
        pq.pop();
        if (d > dist[u][usado]) continue;

        for(auto [v, w] : grafo[u]){

            //nao usar cupom
            if(dist[u][usado]+w<dist[v][usado]){

                dist[v][usado]=dist[u][usado]+ w;

                pq.push({dist[v][usado], v, usado});
            }

            //usar cupom 
            if(!usado){
                ll desconto=w/2;
                if(dist[u][0]+desconto<dist[v][1]){
                    dist[v][1] = dist[u][0] + desconto;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout<<dist[n][1]<<"\n";

}