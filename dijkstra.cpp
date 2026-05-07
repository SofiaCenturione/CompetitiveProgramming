#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
vector<ll> dist;
vector<int> pai;
vector<vector<pair<int, ll>>> adj;

void dijkstra(int s) {
    dist.assign(n + 1, 1e18);
    pai.assign(n + 1, -1);    
    dist[s] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll d = -pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // ignora entradas desatualizadas
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                pai[v] = u;

                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w;
    int a,b;
    cin>>n>>m;
    adj.resize(n + 1);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(1);
    if (dist[n] == 1e18) {
        cout << "-1";
    } else {
        vector<int> caminho;
        for (int curr = n; curr != -1; curr = pai[curr]) {
            caminho.push_back(curr);
        }
        reverse(caminho.begin(), caminho.end());
        for (int no : caminho) {
            cout << no << " ";
        }
        
    }
    cout << "\n";
}