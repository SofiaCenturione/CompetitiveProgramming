#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
vector<ll> dist;//caminho+peso=1e18
vector<vector<pair<int, ll>>> adj;

void dijkstra(int s) {
    dist.assign(n+1,1e18);
    dist[s] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.push({0, s});

    while (!pq.empty()) {   
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin>>n>>m;
    adj.resize(n + 1);
     ll w;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back({b, w});//pq é direcionado insere só 1
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

        

    cout << "\n";
}