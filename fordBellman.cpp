#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u,v,w,n,m;

    cin>>n>>m;
    vector<array<int,3>> edge; //u,v,w

    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }

    vector<int> dist(n+1,1000000000);
    dist[1]=0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edge) 
        {
            int u=e[0]; int v=e[1]; int w=e[2];
            if (dist[u] != inf && dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == inf)
            cout<<30000;
        else
            cout<<dist[i];

        if(i<n)
            cout<<" ";
    }

    cout<<"\n";
}